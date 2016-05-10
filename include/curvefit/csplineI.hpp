/* ************************************************************************** *\
 * csplineI.hpp
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
\* ************************************************************************** */

template <class T>
numlib::CSpline<T>::CSpline(
    numlib::Vector<numlib::Coordinate<T>> const &pts)
{
  points(pts);
}

template <class T>
void
numlib::CSpline<T>::points(
    numlib::Vector<numlib::Coordinate<T>> const &inp)
{
  numlib::TDMA<double> td_solver;
  std::size_t pts = inp.get_size();
  numlib::Vector<double> h(pts-1), b(pts), c, abcd_tmp(4);

  numlib::TriDiag<double> tdmat(pts);

  lx_ = inp[pts-1].x();

  for(std::size_t i=0; i<pts-1; ++i)
  {
    h[i] = inp[i+1].x() - inp[i].x();
  }

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
    tdmat(i,i+1) = h[i];

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
void
numlib::CSpline<T>::points_clamped(
    numlib::Vector<numlib::Coordinate<T>> const &inp, T const &fp0, T const &fpN)
{
  numlib::TDMA<double> td_solver;
  std::size_t pts = inp.get_size();
  numlib::Vector<double> h(pts-1), b(pts), c, abcd_tmp(4);

  numlib::TriDiag<double> tdmat(pts);

  lx_ = inp[pts-1].x();

  for(std::size_t i=0; i<pts-1; ++i)
  {
    h[i] = inp[i+1].x() - inp[i].x();
  }

  tdmat(0,0) = 2*h[0];
  tdmat(0,1) = h[0];
  b[0] = (3/h[0])*(inp[1].y() - inp[0].y()) - 3*fp0;
  tdmat(pts-1,pts-2) = h[pts-2];
  tdmat(pts-1,pts-1) = 2*h[pts-2];
  b[pts-1] = -(3/h[pts-2])*(inp[pts-1].y() - inp[pts-2].y()) + 3*fpN;

  for(std::size_t i=1; i<pts-1; ++i)
  {
    tdmat(i,i-1) = h[i-1];
    tdmat(i,i) = 2*(h[i-1] + h[i]);
    tdmat(i,i+1) = h[i];

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
numlib::CSpline<T>::operator ()(
    T const &x) const
{
  std::size_t cnum = get_cubic(x);
  return cspline_[cnum].value_(x - cspline_[cnum].key_);
}

template <class T>
void
numlib::CSpline<T>::write_octave(
    std::string fname)
{
  std::ofstream fout;
  numlib::Vector<T> a;

  const char *file = (fname + ".m").c_str();

  fout.open(fname + ".m");

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
  fout.close();
  return;
}

template <class T>
std::size_t
numlib::CSpline<T>::get_cubic(T const &x) const
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
