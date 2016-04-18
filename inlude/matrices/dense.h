/*
 *  dense.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Dense Matrix Form class.
 */

#ifndef DENSE_H_
#define DENSE_H_

#include <utility>
#include "matrix.h"

namespace numlib
{
  template <class Type>
  class Dense;

  template <class Type>
  void
  swap(
    Dense<Type> &d1,
    Dense<Type> &d2);

  template <class Type>
  class Dense: public Matrix<Type,Dense>
  {
    public:
      Dense() = default;
      Dense(
        std::size_t const &n);
      Dense(
        std::size_t const &n,
        std::size_t const &m);

      Dense<Type>&
      operator = (
        Dense<Type> cpy);

      Dense(
        Dense<Type> const &src);
      Dense(
        Matrix<Type,Dense> const &src);
      Dense(
        Dense<Type> &&other);
      ~Dense() {}
      // Basic Matrix Math operations
      template <template <class> class F>
      Matrix<Type,Dense>& operator += (Matrix<Type,F> const &rhs);

      template <template <class> class F>
      Matrix<Type,Dense>& operator -= (Matrix<Type,F> const &rhs);

      // template <class F>
      // Form<Type> operator * (Matrix<F> const &rhs) const
      // {
      //   return static_cast<const Form&>(*this) * rhs;
      // }
      //
      // Form<Type> operator * (Vector<Type> const &rhs) const
      // {
      //   return static_cast<const Form&>(*this) * rhs;
      // }

      // Basic Matrix projection, syntax like mat[{i,j}]
      Type operator[](numlib::Vector<std::size_t> ij) const;
      Type& operator[](numlib::Vector<std::size_t> ij);

      // Clone idiom for copying
      std::shared_ptr<Dense<Type>> clone() const;

      // Dimension information access
      std::size_t N() const;
      std::size_t M() const;

      friend void swap <> (Dense<Type> &d1, Dense<Type> &d2);

      // IO Operations
      void print(std::ostream &out) const;

    private:
      numlib::Vector<Type> data_;
      std::size_t n_, m_;
  }; // class Dense
} // namespace numlib

#include "dense.hpp"

#endif
