/*
 *  diagonal.hpp
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Diag Matrix Form class implementation.
 */

template <class Type>
numlib::Diag<Type>::Diag(
  std::size_t const &n):
  data_(n),
  n_(n)
{}

template <class Type>
numlib::Diag<Type>::Diag(
  std::size_t const &n,
  std::size_t const &m):
  data_(n),
  n_(n)
{
}

template <class Type>
numlib::Diag<Type>&
numlib::Diag<Type>::operator = (
  numlib::Diag<Type> cpy)
{
  swap(*this,cpy);

  return *this;
}

template <class Type>
numlib::Diag<Type>::Diag(
  Matrix<Type,Diag> const &src):
  Diag(static_cast<const Diag<Type>&>(src))
{
}

template <class Type>
numlib::Diag<Type>::Diag(
  Diag<Type> const &src):
  data_(src.data_),
  n_(src.n_)
{
}

template <class Type>
numlib::Diag<Type>::Diag(
  Diag<Type> &&other):
  data_(std::move(other.data_)),
  n_(other.n_)
{}

template <class Type>
template <template <class> class F>
numlib::Matrix<Type,F>&
numlib::Diag<Type>::operator + (
  Matrix<Type,F> const &rhs) const
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator + failed");
  Matrix<Type,F>* ret = new F<Type>(rhs);

  for(std::size_t i=0;i<N();++i)
  {
    ret->operator[]({i,i})+=data_[i];
  }
  return *ret;
}

template <class Type>
template <template <class> class F>
numlib::Diag<Type>&
numlib::Diag<Type>::operator += (
  Matrix<Type,F> const &rhs)
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator += failed");

  for(std::size_t i=0; i<N(); ++i)
  {
    data_[i] += rhs[{i,i}];
  }
  return *this;
}

template <class Type>
template <template <class> class F>
numlib::Matrix<Type,F>&
numlib::Diag<Type>::operator - (
  Matrix<Type,F> const &rhs) const
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator - failed");
  Matrix<Type,F>* ret = new F<Type>(rhs);

  for(std::size_t i=0;i<N();++i)
  {
    ret->operator[]({i,i})+=data_[i];
  }
  return *ret;
}

template <class Type>
template <template <class> class F>
numlib::Diag<Type>&
numlib::Diag<Type>::operator -= (
  Matrix<Type,F> const &rhs)
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator += failed");

  for(std::size_t i=0; i<N(); ++i)
  {
    data_[i] -= rhs[{i,i}];
  }
  return *this;
}

template <class Type>
template <template <class> class F>
numlib::Matrix<Type,F>&
numlib::Diag<Type>::operator * (
  Matrix<Type,F> const &rhs) const
{
  if(M() != rhs.N())
    throw numlib::DimensionMismatch(
      "numlib::Diag<Type>operator *(Matrix<Type,F> const &rhs)");

  Matrix<Type,F>* ret = new F<Type>(rhs);

  for(std::size_t i=0; i<N(); ++i)
  {
    for(std::size_t j=0; j<rhs.M(); ++j)
    {
      ret->operator[]({i,j}) = rhs[{i,j}]*data_[i];
    }
  }

  return *ret;
}

template <class Type>
numlib::Vector<Type>
numlib::Diag<Type>::operator * (
  Vector<Type> const &rhs) const
{
  if(M() != rhs.get_size())
    throw DimensionMismatch("Diag::operator *(Vector): Vector");

  Vector<Type> ret(rhs);

  for(std::size_t i=0; i<N(); ++i)
  {
    ret[i] = rhs[i]*data_[i];
  }

  return ret;
}

template <class Type>
Type numlib::Diag<Type>::operator[](
  std::initializer_list<std::size_t> ij) const
{
  if(ij.size() != 2 || *(ij.begin()) >= N() || *(ij.begin()+1) >= M())
    throw RangeException("Diag op []");

  if(*(ij.begin())==*(ij.begin()+1))
    return data_[*(ij.begin())];
  else
    return __empty_const__;
}

template <class Type>
Type& numlib::Diag<Type>::operator[](
  std::initializer_list<std::size_t> ij)
{
  if(ij.size() != 2 || *(ij.begin()) >= N() || *(ij.begin()+1) >= M())
    throw RangeException("Diag op []");

  if(*(ij.begin())==*(ij.begin()+1))
  {
    return data_[*(ij.begin())];
  }
  else
  {
    Type* emp;
    *emp = __empty_const__;
    return *emp;
  }
}

// Clone idiom for copying
template <class Type>
std::shared_ptr<numlib::Diag<Type>>
numlib::Diag<Type>::clone() const
{
  return std::shared_ptr<Diag<Type>>(new Diag<Type>(*this));
}

template <class Type>
std::size_t
numlib::Diag<Type>::N() const
{
  return n_;
}

template <class Type>
std::size_t
numlib::Diag<Type>::M() const
{
  return n_;
}

template <class Type>
inline bool
numlib::Diag<Type>::checki(
    std::size_t const i) const
{
  return (n_)&&(i<n_);
}

template <class Type>
inline bool
numlib::Diag<Type>::checkj(
    std::size_t const j) const
{
  return (n_)&&(j<n_);
}

template <class Type>
void numlib::swap(
  Diag<Type> &d1,
  Diag<Type> &d2)
{
  using std::swap;
  std::swap(d1.data_,d2.data_);
  std::swap(d1.n_, d2.n_);
  return;
}

template <class Type>
void
numlib::Diag<Type>::print(
  std::ostream &out) const
{
  if(N()>0)
  {
    for(std::size_t i=0; i<N(); ++i)
    {
      out << std::setw(8*i) << "" << ' ';
      out << std::left << std::setw(8) << std::scientific
          << data_[i] << ' ';
      out << '\n';
    }
  }
  return;
}

template <class Type>
numlib::Diag<Type> numlib::eye(std::size_t n)
{
  numlib::Diag<Type> eye(n);
  for(std::size_t i=0;i<n;++i)
    eye[{i,i}] = 1;

  return eye;
}
