/*
 *  tridiagonal.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: TriDiag Matrix Form class.
 */

#ifndef TRIDIAGONAL_H_
#define TRIDIAGONAL_H_

#include <utility>
#include "matrix.h"
#include "dense.h"

namespace numlib
{
  template <class Type>
  class TriDiag;

  template <class Type>
  void
  swap(
    TriDiag<Type> &d1,
    TriDiag<Type> &d2);

  template <class Type>
  class TriDiag: public Matrix<Type,TriDiag>
  {
    public:
      TriDiag(): data_(), n_(0) {};
      TriDiag(
        std::size_t const &n);
      TriDiag(
        std::size_t const &n,
        std::size_t const &m);

      TriDiag<Type>&
      operator = (
        TriDiag<Type> cpy);

      TriDiag(
        TriDiag<Type> const &src);
      TriDiag(
        Matrix<Type,TriDiag> const &src);
      TriDiag(
        TriDiag<Type> &&other);
      ~TriDiag() {}

      // Basic Matrix Math operations
      template <template <class> class F>
      Matrix<Type,F>& operator + (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      TriDiag<Type>& operator += (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Matrix<Type,F>& operator - (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      TriDiag<Type>& operator -= (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Matrix<Type,numlib::Dense>& operator * (Matrix<Type,F> const &rhs) const;

      Vector<Type> operator * (Vector<Type> const &rhs) const;

      // Basic Matrix projection, syntax like mat[{i,j}]
      Type operator[](std::initializer_list<std::size_t> ij) const;
      Type& operator[](std::initializer_list<std::size_t> ij);

      // Clone idiom for copying
      std::shared_ptr<TriDiag<Type>> clone() const;

      // Dimension information access
      std::size_t N() const;
      std::size_t M() const;
      bool checki(std::size_t const i) const;
      bool checkj(std::size_t const j) const;

      friend void swap <> (TriDiag<Type> &d1, TriDiag<Type> &d2);

      // IO Operations
      void print(std::ostream &out) const;

    private:
      numlib::Vector<Type> data_;
      std::size_t n_;
      constexpr static const Type __empty_const__ = 0;
      Type dummy;
  }; // class TriDiag
} // namespace numlib

#include "tridiagonal.hpp"

#endif
