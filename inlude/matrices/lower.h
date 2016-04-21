/*
 *  lower.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Upper Triangle Matrix Form class.
 */

#ifndef LOWERTRIANGLE_H_
#define LOWERTRIANGLE_H_

#include <utility>
#include "matrix.h"
#include "dense.h"

namespace numlib
{
  template <class Type>
  class LowerTriangle;

  template <class Type>
  void
  swap(
    LowerTriangle<Type> &d1,
    LowerTriangle<Type> &d2);

  template <class Type>
  class LowerTriangle: public Matrix<Type,LowerTriangle>
  {
    public:
      LowerTriangle(): data_(), n_(0) {};
      LowerTriangle(
        std::size_t const &n);
      LowerTriangle(
        std::size_t const &n,
        std::size_t const &m);

      LowerTriangle<Type>&
      operator = (
        LowerTriangle<Type> cpy);

      LowerTriangle(
        LowerTriangle<Type> const &src);
      LowerTriangle(
        Matrix<Type,LowerTriangle> const &src);
      LowerTriangle(
        LowerTriangle<Type> &&other);
      ~LowerTriangle() {}

      // Basic Matrix Math operations
      template <template <class> class F>
      LowerTriangle<Type> operator + (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      LowerTriangle<Type>& operator += (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      LowerTriangle<Type> operator - (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      LowerTriangle<Type>& operator -= (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Matrix<Type,Dense>& operator * (Matrix<Type,F> const &rhs) const;

      Vector<Type> operator * (Vector<Type> const &rhs) const;

      // Basic Matrix projection, syntax like mat[{i,j}]
      Type operator[](std::initializer_list<std::size_t> ij) const;
      Type& operator[](std::initializer_list<std::size_t> ij);

      // Clone idiom for copying
      std::shared_ptr<LowerTriangle<Type>> clone() const;

      // Dimension information access
      std::size_t N() const;
      std::size_t M() const;
      bool checki(std::size_t const i) const;
      bool checkj(std::size_t const j) const;

      friend void swap <> (LowerTriangle<Type> &d1, LowerTriangle<Type> &d2);

      // IO Operations
      void print(std::ostream &out) const;

    private:
      numlib::Vector<Type> data_;
      std::size_t n_;
      constexpr static const Type __empty_const__ = 0;
      Type dummy = 0;
  }; // class LowerTriangle
} // namespace numlib

#include "lower.hpp"

#endif // UPPERTRIANGLE_H_
