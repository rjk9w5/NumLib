/*
 *  symmetric.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Upper Triangle Matrix Form class.
 */

#ifndef SYMMETRIC_H_
#define SYMMETRIC_H_

#include <utility>
#include "matrix.h"
#include "dense.h"

namespace numlib
{
  template <class Type>
  class Symmetric;

  template <class Type>
  void
  swap(
    Symmetric<Type> &d1,
    Symmetric<Type> &d2);

  template <class Type>
  class Symmetric: public Matrix<Type,Symmetric>
  {
    public:
      Symmetric(): data_(), n_(0) {};
      Symmetric(
        std::size_t const &n);
      Symmetric(
        std::size_t const &n,
        std::size_t const &m);

      Symmetric<Type>&
      operator = (
        Symmetric<Type> cpy);

      Symmetric(
        Symmetric<Type> const &src);
      Symmetric(
        Matrix<Type,Symmetric> const &src);
      Symmetric(
        Symmetric<Type> &&other);
      ~Symmetric() {}

      // Basic Matrix Math operations
      template <template <class> class F>
      Symmetric<Type> operator + (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      Symmetric<Type>& operator += (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Symmetric<Type> operator - (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      Symmetric<Type>& operator -= (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Matrix<Type,Dense>& operator * (Matrix<Type,F> const &rhs) const;

      Vector<Type> operator * (Vector<Type> const &rhs) const;

      // Basic Matrix projection, syntax like mat[{i,j}]
      Type operator[](std::initializer_list<std::size_t> ij) const;
      Type& operator[](std::initializer_list<std::size_t> ij);

      // Clone idiom for copying
      std::shared_ptr<Symmetric<Type>> clone() const;

      // Dimension information access
      std::size_t N() const;
      std::size_t M() const;
      bool checki(std::size_t const i) const;
      bool checkj(std::size_t const j) const;

      friend void swap <> (Symmetric<Type> &d1, Symmetric<Type> &d2);

      // IO Operations
      void print(std::ostream &out) const;

    private:
      numlib::Vector<Type> data_;
      std::size_t n_;
      constexpr static const Type __empty_const__ = 0;
  }; // class Symmetric
} // namespace numlib

#include "symmetric.hpp"

#endif // UPPERTRIANGLE_H_
