/*
 *  diagonal.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Diag Matrix Form class.
 */

#ifndef DIAGONAL_H_
#define DIAGONAL_H_

#include <utility>
#include "matrix.h"

namespace numlib
{
  template <class Type>
  class Diag;

  template <class Type>
  void
  swap(
    Diag<Type> &d1,
    Diag<Type> &d2);

  template <class Type>
  Diag<Type>
  eye(
    std::size_t n);

  template <class Type>
  class Diag: public Matrix<Type,Diag>
  {
    public:
      Diag(): data_(), n_(0) {};
      Diag(
        std::size_t const &n);
      Diag(
        std::size_t const &n,
        std::size_t const &m);

      Diag<Type>&
      operator = (
        Diag<Type> cpy);

      Diag(
        Diag<Type> const &src);
      Diag(
        Matrix<Type,Diag> const &src);
      Diag(
        Diag<Type> &&other);
      ~Diag() {}

      // Basic Matrix Math operations
      template <template <class> class F>
      Matrix<Type,F>& operator + (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      Diag<Type>& operator += (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Matrix<Type,F>& operator - (Matrix<Type,F> const &rhs) const;

      template <template <class> class F>
      Diag<Type>& operator -= (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Matrix<Type,F>& operator * (Matrix<Type,F> const &rhs) const;

      Vector<Type> operator * (Vector<Type> const &rhs) const;

      // Basic Matrix projection, syntax like mat[{i,j}]
      Type operator[](std::initializer_list<std::size_t> ij) const;
      Type& operator[](std::initializer_list<std::size_t> ij);

      // Clone idiom for copying
      std::shared_ptr<Diag<Type>> clone() const;

      // Dimension information access
      std::size_t N() const;
      std::size_t M() const;
      bool checki(std::size_t const i) const;
      bool checkj(std::size_t const j) const;

      friend void swap <> (Diag<Type> &d1, Diag<Type> &d2);

      // IO Operations
      void print(std::ostream &out) const;

    private:
      numlib::Vector<Type> data_;
      std::size_t n_;
      constexpr static const Type __empty_const__ = 0;
  }; // class Diag
} // namespace numlib

#include "diagonal.hpp"

#endif
