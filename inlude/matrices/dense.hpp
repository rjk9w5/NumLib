/*
 *  dense.hpp
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Dense Matrix Form class implementation.
 */

template <class Type>
numlib::Dense<Type>::Dense(
  std::size_t const &n):
  data_(n*n),
  n_(n),
  m_(n)
{}

template <class Type>
numlib::Dense<Type>::Dense(
  std::size_t const &n,
  std::size_t const &m):
  data_(n*m),
  n_(n),
  m_(m)
{}

template <class Type>
numlib::Dense<Type>&
numlib::Dense<Type>::operator = (
  numlib::Dense<Type> cpy)
{
  swap(*this,cpy);

  return *this;
}

template <class Type>
numlib::Dense<Type>::Dense(
  MatrixCRTP<Type,Dense> const &src):
  Dense(static_cast<const Dense<Type>&>(src))
{
}

template <class Type>
numlib::Dense<Type>::Dense(
  Dense<Type> const &src):
  data_(src.data_),
  n_(src.n_),
  m_(src.m_)
{}

template <class Type>
numlib::Dense<Type>::Dense(
  Dense<Type> &&other):
  data_(std::move(other.data_)),
  n_(other.n_),
  m_(other.m_)
{}

template <class Type>
template <template <class> class F>
numlib::MatrixCRTP<Type,numlib::Dense>&
numlib::Dense<Type>::operator += (
  MatrixCRTP<Type,F> const &rhs)
{
  if(n_!=rhs.N()||m_!=rhs.M()) throw DimensionMismatch("MatrixCRTP addition with operator += failed");
  for(std::size_t i=0; i<n_; ++i)
  {
    for(std::size_t j=0; j<m_; ++j)
    {
      this->operator[]({i,j}) += rhs[{i,j}];
    }
  }
  return *this;
}

template <class Type>
template <template <class> class F>
numlib::MatrixCRTP<Type,numlib::Dense>&
numlib::Dense<Type>::operator -= (
  MatrixCRTP<Type,F> const &rhs)
{
  if(n_!=rhs.N()||m_!=rhs.M()) throw DimensionMismatch("MatrixCRTP addition with operator += failed");
  for(std::size_t i=0; i<n_; ++i)
  {
    for(std::size_t j=0; j<m_; ++j)
    {
      this->operator[]({i,j}) -= rhs[{i,j}];
    }
  }
  return *this;
}

template <class Type>
Type numlib::Dense<Type>::operator[](numlib::Vector<std::size_t> ij) const
{
  return data_[ij[0]*m_ + ij[1]];
}

template <class Type>
Type& numlib::Dense<Type>::operator[](numlib::Vector<std::size_t> ij)
{
  return data_[ij[0]*m_ + ij[1]];
}

// Clone idiom for copying
template <class Type>
std::shared_ptr<numlib::Dense<Type>>
numlib::Dense<Type>::clone() const
{
  return std::shared_ptr<Dense<Type>>(new Dense<Type>(*this));
}

template <class Type>
std::size_t
numlib::Dense<Type>::N() const
{
  return n_;
}

template <class Type>
std::size_t
numlib::Dense<Type>::M() const
{
  return m_;
}

template <class Type>
void numlib::swap(Dense<Type> &d1, Dense<Type> &d2)
{
  using std::swap;
  std::swap(d1.data_,d2.data_);
  std::swap(d1.n_, d2.n_);
  std::swap(d1.m_, d2.m_);
  return;
}

template <class Type>
void
numlib::Dense<Type>::print(
  std::ostream &out) const
{
  if(n_>0 && m_>0)
  {
    for(std::size_t i=0; i<n_; ++i)
    {
      for(std::size_t j=0; j<m_; ++j)
      {
        out << std::left << std::setw(8) << std::scientific << this->operator[]({i,j}) << ' ';
      }
      out << '\n';
    }
  }
  return;
}
