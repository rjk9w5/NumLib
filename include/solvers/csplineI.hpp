/* ************************************************************************** *\
 * csplineI.hpp
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */

template <class T>
oonm::CSpline<T>::CSpline(
    oonm::Vector<oonm::Coordinate<T>> const &pts)
{
  points(pts);
}

template <class T>
void
oonm::CSpline<T>::points(
    oonm::Vector<oonm::Coordinate<T>> const &inp)
{
  oonm::TDMA<double> td_solver;
  std::size_t pts = inp.get_size();
  oonm::Vector<double> h, b, c, abcd_tmp(4);

  oonm::MatrixTriDiag<double> tdmat;

  lx_ = inp[pts-1].x();

  h.set_size(pts-1);

  for(std::size_t i=0; i<pts-1; ++i)
  {
    h[i] = inp[i+1].x() - inp[i].x();
  }

  tdmat.set_size(pts);
  b.set_size(pts);
  tdmat(0,0) = 1;
  tdmat(0,1) = 0;
  b[0] = 0;
  tdmat(pts-1,pts-2) = 0;
  tdmat(pts-1,pts-1) = 1;
  b[pts-1] = 0;

  for(std::size_t i=1; i<pts-1; ++i)
  {
    tdmat(i,i-1) = h[i-1];
    tdmat(i,i) = 2*(h[i-1] + h[i]);
    tdmat(i,i+1) = h[i+1];

    b[i] = (3/h[i])*(inp[i+1].y() - inp[i].y()) -
           (3/h[i-1])*(inp[i].y() - inp[i-1].y());
  }

  c = td_solver(tdmat,b);

  cspline_.set_size(pts-1);

  for(std::size_t i=0; i<pts-1; ++i)
  {
    cspline_[i].key_ = inp[i].x();

    abcd_tmp[0] = inp[i].y();
    abcd_tmp[1] = (1/h[i])*(inp[i+1].y() - inp[i].y()) -
                  (h[i]/3)*(2*c[i] + c[i+1]);
    abcd_tmp[2] = c[i];
    abcd_tmp[3] = (c[i+1] - c[i])/(3*h[i]);

    cspline_[i].value_.coeff(abcd_tmp);
  }
}

template <class T>
T
oonm::CSpline<T>::operator ()(
    T const &x) const
{
  std::size_t cnum = get_cubic(x);
  return cspline_[cnum].value_(x - cspline_[cnum].key_);
}

template <class T>
void
oonm::CSpline<T>::write_octave(
    std::string fname)
{
  std::ofstream fout;
  oonm::Vector<T> a;

  const char *file = (fname + ".m").c_str();

  fout.open(file);

  if(!fout.is_open()) std::cerr << "OOPS!\n";

  fout << "function [y] = " << fname << "(x)\n";
  fout << "  N = max(size(x));\n  y=zeros(N,1);\n\n";
  for(std::size_t i=0; i<cspline_.get_size(); ++i)
  {
    a = cspline_[i].value_.get_coeff();
    fout << "  f" << i << " = @(xx) " << a[0];
    for(std::size_t k=1; k<4; ++k)
      fout << " + " << a[k] << "*xx.^" << k;
    fout << ";\n";
  }
  fout << '\n';
  fout << "  for i = 1:1:N" << '\n';
  for(std::size_t i=0; i<cspline_.get_size()-1; ++i)
  {
    fout << (i==0?"    if ":"    elseif ") << cspline_[i].key_ << " <= x(i) && "
         << cspline_[i+1].key_<< " > x(i)\n";
    fout << "      y(i) = f" << i << "(x(i) - " << cspline_[i].key_ << ");\n";
  }
  if(cspline_.get_size() > 0)
  {
    fout << "    elseif " << cspline_[cspline_.get_size()-1].key_ << " <= x(i) && "
         << lx_<< " >= x(i)\n";
    fout << "      y(i) = f" << cspline_.get_size()-1 << "(x(i) - " << cspline_[cspline_.get_size()-1].key_ << ");\n";
  }
  fout << "    elseif " << lx_<< " < x(i)\n";
  fout << "      fprintf('Warning: Evaluating Cublic Spline above range\\n')\n";
  fout << "      y(i) = f" << cspline_.get_size()-1 << "(x(i) - " << cspline_[cspline_.get_size()-1].key_ << ");\n";

  fout << "    elseif " << cspline_[0].key_<< " > x(i)\n";
  fout << "      fprintf('Warning: Evaluating Cublic Spline below range\\n')\n";
  fout << "      y(i) = f" << 0 << "(x(i) - " << cspline_[0].key_ << ");\n";

  fout << "  end\n";
  fout << "end\n";
}

template <class T>
std::size_t
oonm::CSpline<T>::get_cubic(T const &x) const
{
  std::size_t cnum = 0;
  if(cspline_[cnum] > x)
  {
    std::cerr << "Warning: Evaluating spline below bounds\n";
    return cnum;
  }
  while(cspline_[++cnum] < x && cnum < cspline_.get_size())
  {
  }
  if(cnum == cspline_.get_size())
  {
    if(x > lx_)
      std::cerr << "Warning: Evaluating spline above bounds\n";

    --cnum;
  }

  return cnum;
}
