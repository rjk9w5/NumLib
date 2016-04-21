/*
 * qr_orthonormal.hpp
 *
 *  Created on: Feb 24, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
 */

template <class Type>
void numlib::QR_OrthoNormal<Type>::operator() (
  numlib::Dense<Type> const &A,
  numlib::Dense<Type> &Q,
  numlib::UpperTriangle<Type> &R)
{
  std::size_t n = A.M(); // Number of vectors in set
  Vector<Vector<Type>> u, a;

  if(!(n > 0 && A.M()==A.N()))
    throw DimensionMismatch("numlib::QR_OrthoNormal::operator()(...)");

    // Initialize u as a copy of A in vector form
    u.set_size(n);
    for(std::size_t i=0;i<n;++i)
    {
      u[i].set_size(n);
      for(std::size_t j=0; j<n; ++j)
      {
        u[i][j] = A[{j,i}];
      }
    }
    a = u;

    for(size_t k=0; k<n; ++k)
    {
      for(size_t j=k+1; j<n; ++j)
      {
        u[j] -= proj(u[k],a[j]);
      }
    }

    for(std::size_t k=0; k<n; ++k)
      unitize(u[k]);

    Q = makeQ(u);
    R = makeR(u,a);

  return;
}

template<class Type>
numlib::Vector<Type>
numlib::QR_OrthoNormal<Type>::proj(
  numlib::Vector<Type> const &e,
  numlib::Vector<Type> const &a)
{
  return ((e*a)/(e*e))*e;
}

template<class Type>
void
numlib::QR_OrthoNormal<Type>::unitize(numlib::Vector<Type> &u2e)
{
  Type norm = sqrt(u2e*u2e);

  for(auto& u: u2e)
    u/=norm;

  return;
}

template<class Type>
numlib::Dense<Type>
numlib::QR_OrthoNormal<Type>::makeQ(
  Vector<Vector<Type>> const &e)
{
  Dense<Type> ret(e.get_size());
  for(std::size_t j=0; j<e.get_size(); ++j)
  {
    for(std::size_t i=0; i<e.get_size(); ++i)
    {
      ret[{i,j}] = e[j][i];
    }
  }

  return ret;
}

template<class Type>
numlib::UpperTriangle<Type>
numlib::QR_OrthoNormal<Type>::makeR(
  Vector<Vector<Type>> const &e,
  Vector<Vector<Type>> const &a)
{
  UpperTriangle<Type> ret(e.get_size());

  for(std::size_t i=0; i<e.get_size(); ++i)
  {
    for(std::size_t j=i; j<e.get_size(); ++j)
    {
      ret[{i,j}] = e[i]*a[j];
    }
  }

  return ret;
}
