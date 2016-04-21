/*
 *  tridiagonal.hpp
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: TriDiag Matrix Form class implementation.
 */

template <class Type>
numlib::TriDiag<Type>::TriDiag(
  std::size_t const &n):
  data_(3*n-2),
  n_(n)
{}

template <class Type>
numlib::TriDiag<Type>::TriDiag(
  std::size_t const &n,
  std::size_t const &m):
  data_(3*n-2),
  n_(n)
{
}

template <class Type>
numlib::TriDiag<Type>&
numlib::TriDiag<Type>::operator = (
  numlib::TriDiag<Type> cpy)
{
  swap(*this,cpy);

  return *this;
}

template <class Type>
numlib::TriDiag<Type>::TriDiag(
  Matrix<Type,TriDiag> const &src):
  TriDiag(static_cast<const TriDiag<Type>&>(src))
{
}

template <class Type>
numlib::TriDiag<Type>::TriDiag(
  TriDiag<Type> const &src):
  data_(src.data_),
  n_(src.n_)
{
}

template <class Type>
numlib::TriDiag<Type>::TriDiag(
  TriDiag<Type> &&other):
  data_(std::move(other.data_)),
  n_(other.n_)
{}

template <class Type>
template <template <class> class F>
numlib::Matrix<Type,F>&
numlib::TriDiag<Type>::operator + (
  Matrix<Type,F> const &rhs) const
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator + failed");

  Matrix<Type,F> *ret = new F<Type>(rhs);

  for(std::size_t i=0;i<n_;++i)
  {
    for(std::size_t j=(i?i-1:i); j<(i+1<n_?i+1:i); ++j)
    {
      ret->operator[]({i,j}) += this->operator[]({i,j});
    }
  }
  return *ret;
}

template <class Type>
template <template <class> class F>
numlib::TriDiag<Type>&
numlib::TriDiag<Type>::operator += (
  Matrix<Type,F> const &rhs)
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator += failed");

  for(std::size_t i=0;i<n_;++i)
  {
    for(std::size_t j=(i?i-1:i); j<(i+1<n_?i+1:i); ++j)
    {
      this->operator[]({i,j}) += rhs[{i,j}];
    }
  }
  return *this;
}

template <class Type>
template <template <class> class F>
numlib::Matrix<Type,F>&
numlib::TriDiag<Type>::operator - (
  Matrix<Type,F> const &rhs) const
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator + failed");

  Matrix<Type,F> *ret = new F<Type>(rhs);

  for(std::size_t i=0;i<n_;++i)
  {
    for(std::size_t j=(i?i-1:i); j<(i+1<n_?i+1:i); ++j)
    {
      ret->operator[]({i,j}) -= this->operator[]({i,j});
    }
  }
  return *ret;
}

template <class Type>
template <template <class> class F>
numlib::TriDiag<Type>&
numlib::TriDiag<Type>::operator -= (
  Matrix<Type,F> const &rhs)
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator += failed");

  for(std::size_t i=0;i<n_;++i)
  {
    for(std::size_t j=(i?i-1:i); j<(i+1<n_?i+1:i); ++j)
    {
      this->operator[]({i,j}) -= rhs[{i,j}];
    }
  }
  return *this;
}
// Re-write to be more efficient for TriDiagonal Form matrices!
template <class Type>
template <template <class> class F>
numlib::Matrix<Type,numlib::Dense>&
numlib::TriDiag<Type>::operator * (
  Matrix<Type,F> const &rhs) const
{
  if(M() != rhs.N())
    throw numlib::DimensionMismatch(
      "numlib::Dense<Type>operator *(Matrix<Type,F> const &rhs)");

  Matrix<Type,Dense>* ret = new Dense<Type>(N(), rhs.M());

  for(std::size_t i=0; i<N(); ++i)
  {
    for(std::size_t j=0; j<M(); ++j)
    {
      ret->operator[]({i,j}) = 0;
      for(std::size_t k=0; k<N(); ++k)
      {
        ret->operator[]({i,j}) += this->operator[]({i,k})*rhs[{k,j}];
      }
    }
  }

  return *ret;
}
// Re-write to be more efficient for TriDiagonal Form matrices!
template <class Type>
numlib::Vector<Type>
numlib::TriDiag<Type>::operator * (
  Vector<Type> const &rhs) const
{
  if(M() != rhs.get_size())
    throw DimensionMismatch("Dense::operator *(Vector): Vector");

  Vector<Type> ret(rhs);

  for(std::size_t i=0; i<N(); ++i)
  {
    ret[i] = 0;
    for(std::size_t k=0; k<M(); ++k)
    {
      ret[i] += this->operator[]({i,k})*rhs[k];
    }
  }

  return ret;
}

template <class Type>
Type numlib::TriDiag<Type>::operator[](
  std::initializer_list<std::size_t> ij) const
{
  if(ij.size() != 2 || *(ij.begin()) >= N() || *(ij.begin()+1) >= M())
    throw RangeException("TriDiag op []");

  std::size_t i(*(ij.begin())), j(*(ij.begin()+1));

  if(abs(j-i)<=1)
    return data_[3*i + static_cast<int>(j-i)];
  else
    return __empty_const__;
}

template <class Type>
Type& numlib::TriDiag<Type>::operator[](
  std::initializer_list<std::size_t> ij)
{
  if(ij.size() != 2 || *(ij.begin()) >= N() || *(ij.begin()+1) >= M())
    throw RangeException("TriDiag op []");

  std::size_t i(*(ij.begin())), j(*(ij.begin()+1));

  if(abs(j-i)<=1)
  {
    return data_[3*i + static_cast<int>(j-i)];
  }
  else
  {
    dummy=0;
    return dummy;
  }
}

// Clone idiom for copying
template <class Type>
std::shared_ptr<numlib::TriDiag<Type>>
numlib::TriDiag<Type>::clone() const
{
  return std::shared_ptr<TriDiag<Type>>(new TriDiag<Type>(*this));
}

template <class Type>
std::size_t
numlib::TriDiag<Type>::N() const
{
  return n_;
}

template <class Type>
std::size_t
numlib::TriDiag<Type>::M() const
{
  return n_;
}

template <class Type>
inline bool
numlib::TriDiag<Type>::checki(
    std::size_t const i) const
{
  return (n_)&&(i<n_);
}

template <class Type>
inline bool
numlib::TriDiag<Type>::checkj(
    std::size_t const j) const
{
  return (n_)&&(j<n_);
}

template <class Type>
void numlib::swap(
  TriDiag<Type> &d1,
  TriDiag<Type> &d2)
{
  using std::swap;
  std::swap(d1.data_,d2.data_);
  std::swap(d1.n_, d2.n_);
  return;
}
// Re-write to be more efficient for TriDiagonal Form matrices!
template <class Type>
void
numlib::TriDiag<Type>::print(
  std::ostream &out) const
{
  if(N()>0)
  {
    for(std::size_t i=0; i<data_.get_size()-2; ++i)
    {
      out << std::left << std::setw(output::__width__)
          << std::setprecision(output::__precision__) << std::scientific
          << data_[i] << (i%3==1?'\n':' ');
    }
    out << std::setw(output::__width__+1) << ' ';
    for(std::size_t i=data_.get_size()-2; i<data_.get_size(); ++i)
    {
      out << std::left << std::setw(output::__width__)
          << std::setprecision(output::__precision__) << std::scientific
          << data_[i] << (i%3==1?'\n':' ');
    }
  }
  return;
}
