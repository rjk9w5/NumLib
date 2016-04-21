/*
 *  upper.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Upper Triangle Matrix Form class.
 */

#ifndef UPPERTRIANGLE_H_
#define UPPERTRIANGLE_H_

#include <utility>
#include "matrix.h"
#include "dense.h"

namespace numlib
{
  template <class Type>
  class UpperTriangle;

  template <class Type>
  void
  swap(
    UpperTriangle<Type> &d1,
    UpperTriangle<Type> &d2);

  template <class Type>
  class UpperTriangle: public Matrix<Type,UpperTriangle>
  {
    public:
      UpperTriangle(): data_(), n_(0) {};
      UpperTriangle(
        std::size_t const &n);
      UpperTriangle(
        std::size_t const &n,
        std::size_t const &m);

      UpperTriangle<Type>&
      operator = (
        UpperTriangle<Type> cpy);

      UpperTriangle(
        UpperTriangle<Type> const &src);
      UpperTriangle(
        Matrix<Type,UpperTriangle> const &src);
      UpperTriangle(
        UpperTriangle<Type> &&other);
      ~UpperTriangle() {}

      // Basic Matrix Math operations
      template <template <class> class F>
      UpperTriangle<Type> operator + (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      UpperTriangle<Type>& operator += (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      UpperTriangle<Type> operator - (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      UpperTriangle<Type>& operator -= (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Matrix<Type,Dense>& operator * (Matrix<Type,F> const &rhs) const;

      Vector<Type> operator * (Vector<Type> const &rhs) const;

      // Basic Matrix projection, syntax like mat[{i,j}]
      Type operator[](std::initializer_list<std::size_t> ij) const;
      Type& operator[](std::initializer_list<std::size_t> ij);

      // Clone idiom for copying
      std::shared_ptr<UpperTriangle<Type>> clone() const;

      // Dimension information access
      std::size_t N() const;
      std::size_t M() const;
      bool checki(std::size_t const i) const;
      bool checkj(std::size_t const j) const;

      friend void swap <> (UpperTriangle<Type> &d1, UpperTriangle<Type> &d2);

      // IO Operations
      void print(std::ostream &out) const;

    private:
      numlib::Vector<Type> data_;
      std::size_t n_;
      constexpr static const Type __empty_const__ = 0;
      Type dummy = 0;
  }; // class UpperTriangle
} // namespace numlib

#include "upper.hpp"

#endif // UPPERTRIANGLE_H_
