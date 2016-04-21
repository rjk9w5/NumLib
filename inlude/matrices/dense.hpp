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
{
}

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
  Matrix<Type,Dense> const &src):
  Dense(static_cast<const Dense<Type>&>(src))
{
}

template <class Type>
numlib::Dense<Type>::Dense(
  Dense<Type> const &src):
  data_(src.data_),
  n_(src.n_),
  m_(src.m_)
{
}

template <class Type>
numlib::Dense<Type>::Dense(
  Dense<Type> &&other):
  data_(std::move(other.data_)),
  n_(other.n_),
  m_(other.m_)
{}

template <class Type>
template <template <class> class F>
numlib::Dense<Type>
numlib::Dense<Type>::operator + (
  Matrix<Type,F> const &rhs) const
{
  numlib::Dense<Type> ret(*this);
  return ret+=rhs;
}

template <class Type>
template <template <class> class F>
numlib::Dense<Type>&
numlib::Dense<Type>::operator += (
  Matrix<Type,F> const &rhs)
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator += failed");

  for(std::size_t i=0; i<N(); ++i)
  {
    for(std::size_t j=0; j<M(); ++j)
    {
      this->operator[]({i,j}) += rhs[{i,j}];
    }
  }
  return *this;
}

template <class Type>
template <template <class> class F>
numlib::Dense<Type>
numlib::Dense<Type>::operator - (
  Matrix<Type,F> const &rhs) const
{
  numlib::Dense<Type> ret(*this);
  return ret-=rhs;
}

template <class Type>
template <template <class> class F>
numlib::Dense<Type>&
numlib::Dense<Type>::operator -= (
  Matrix<Type,F> const &rhs)
{
  if(N()!=rhs.N()||M()!=rhs.M())
    throw DimensionMismatch("Matrix addition with operator += failed");

  for(std::size_t i=0; i<N(); ++i)
  {
    for(std::size_t j=0; j<M(); ++j)
    {
      this->operator[]({i,j}) -= rhs[{i,j}];
    }
  }
  return *this;
}

template <class Type>
template <template <class> class F>
numlib::Dense<Type>
numlib::Dense<Type>::operator * (
  Matrix<Type,F> const &rhs) const
{
  if(M() != rhs.N())
    throw numlib::DimensionMismatch(
      "numlib::Dense<Type>operator *(Matrix<Type,F> const &rhs)");

  Dense<Type> ret(N(), rhs.M());

  for(std::size_t i=0; i<N(); ++i)
  {
    for(std::size_t j=0; j<M(); ++j)
    {
      ret[{i,j}] = 0;
      for(std::size_t k=0; k<M(); ++k)
      {
        ret[{i,j}] += this->operator[]({i,k})*rhs[{k,j}];
      }
    }
  }

  return ret;
}

template <class Type>
numlib::Vector<Type>
numlib::Dense<Type>::operator * (
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
Type numlib::Dense<Type>::operator[](
  std::initializer_list<std::size_t> ij) const
{
  if(ij.size() != 2 || *(ij.begin()) >= N() || *(ij.begin()+1) >= M())
    throw RangeException("Dense op []");

  return data_[*(ij.begin())*M() + *(ij.begin()+1)];
}

template <class Type>
Type& numlib::Dense<Type>::operator[](
  std::initializer_list<std::size_t> ij)
{
  if(ij.size() != 2 || *(ij.begin()) >= N() || *(ij.begin()+1) >= M())
    throw RangeException("Dense op []");

  return data_[*(ij.begin())*M() + *(ij.begin()+1)];
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
inline bool
numlib::Dense<Type>::checki(
    std::size_t const i) const
{
  return (n_)&&(i<n_);
}

template <class Type>
inline bool
numlib::Dense<Type>::checkj(
    std::size_t const j) const
{
  return (m_)&&(j<m_);
}

template <class Type>
void numlib::swap(
  Dense<Type> &d1,
  Dense<Type> &d2)
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
        out << std::left << std::setw(8) << std::scientific
            << data_[i*m_ + j] << ' ';
      }
      out << '\n';
    }
  }
  return;
}

// template <class Type>
// void
// numlib::Dense<Type>::read(
//   std::istream &in) const
// {
//   std::size_t n,m;
//   if()
//   if(n_>0 && m_>0)
//   {
//     for(std::size_t i=0; i<n_; ++i)
//     {
//       for(std::size_t j=0; j<m_; ++j)
//       {
//         out << std::left << std::setw(8) << std::scientific
//             << data_[i*m_ + j] << ' ';
//       }
//       out << '\n';
//     }
//   }
//   return;
// }
