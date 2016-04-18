/* ************************************************************************** *\
 * vectorG.hpp
 *
 *  Created on: Mar 12, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
\* ************************************************************************** */


template <class Ele_T>
void numlib::swap(numlib::Vector<Ele_T> &v1, numlib::Vector<Ele_T> &v2)
{
  using std::swap;

  swap(v1.data_,v2.data_);
  swap(v1.size_, v2.size_);

  return;
}

template <class T>
numlib::Vector<T> numlib::operator * (const T& C, const numlib::Vector<T>& v2)
{
  return v2*C;
}

template <class T>
numlib::Vector<T> numlib::operator + (const numlib::Vector<T>& v1,
                                  const numlib::Vector<T>& v2)
{
  numlib::Vector<T> ret(v1);

  return ret += v2;
}

template <class T>
numlib::Vector<T> numlib::operator - (const numlib::Vector<T>& v1,
                            const numlib::Vector<T>& v2)
{
  numlib::Vector<T> ret(v1);

  return ret-=v2;
}

template <class T>
numlib::Vector<T> numlib::operator - (const numlib::Vector<T>& vec)
{
  numlib::Vector<T> ret(vec);
  size_t it=-1;
  for(auto& val: vec)
    ret[++it] = -val;

  return ret;
}

template <class T>
bool numlib::operator == (const numlib::Vector<T>& lhs,
                  const numlib::Vector<T>& rhs)
{
  size_t i = 0;
  if(lhs.size_ == rhs.size_)
  {
    while(i < lhs.size_ && rhs.data_[i] == lhs.data_[i])
    {
      ++i;
    }
  }

  return (i==rhs.size_ && i==lhs.size_)?true:false;
}

template <class T>
bool numlib::operator != (const numlib::Vector<T>& lhs, const numlib::Vector<T>& rhs)
{
    return !(lhs==rhs);
}

template <class T>
std::ostream& numlib::operator<<(std::ostream& out, const numlib::Vector<T>& vec)
{
  for(size_t i=0; i<vec.size_; ++i)
  {
    out << std::scientific
        << std::setprecision(4)
        << std::setw(12)
        << std::left
        << std::setfill(' ')
        << vec.data_[i];
    out << '\n';
  }
  return out;
}

template <class T>
std::istream& numlib::operator>>(std::istream& in, numlib::Vector<T>& vec)
{
  for(size_t i=0; i<vec.size_ && !in.eof(); ++i)
  {
    in >> vec[i];
  }

  if(in.eof())
    throw numlib::FatalError("Vector: operator >>: Invalid input format!");

  return in;
}

template <class T>
numlib::Vector<T> numlib::cat(const numlib::Vector<T>& a1, const numlib::Vector<T>& a2)
{
  numlib::Vector<T> ret(a1.get_size() + a2.get_size());
  int i=-1;
  for(auto& val: a1)
    ret[++i] = val;

  for(auto& val: a2)
    ret[++i] = val;

   return ret;
}

template <class T>
T numlib::sum(const numlib::Vector<T>& vec)
{
  return vec.sum();
}

template <class T>
numlib::Vector<T> sqrt(const numlib::Vector<T>& vec)
{
  numlib::Vector<T> ret(vec.get_size());
  size_t it = 0;

  for(auto& val: vec)
  {
    ret[it++] = sqrt(val);
  }

  return ret;
}

template <class T>
numlib::Vector<T> abs(const numlib::Vector<T>& vec)
{
  numlib::Vector<T> ret(vec.get_size());
  size_t it = 0;

  for(auto& val: vec)
  {
    ret[it++] = abs(val);
  }

  return ret;
}
