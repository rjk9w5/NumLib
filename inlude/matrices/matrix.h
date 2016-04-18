/*
 *  matrix.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Base Matrix class for CRTP interface type.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "../vector/vector.h"
#include <memory>
#include <ostream>

namespace numlib
{
  template <class Type>
  class Matrix;

  template <class Type>
  class Matrix:public virtual Matrix<Type>
  {
    public:
      // Matrix<Type,Form>&
      // operator = (
      //   Matrix<Type,Form> const &src)
      // {
      //   std::cout << "op = from Matrix<Type,Form>\n";
      //   return this->operator=(static_cast<const Form<Type>&>(src));
      // }

      // Basic Matrix Math operations
      virtual Matrix<Type>& operator + (Matrix<Type> const &rhs) const = 0;

      virtual Matrix<Type>& operator += (Matrix<Type> const &rhs) = 0;

      // template <class F>
      // Form<Type> operator - (Matrix<F> const &rhs) const
      // {
      //   return static_cast<const Form&>(*this) - rhs;
      // }
      //
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
      virtual Type operator[](numlib::Vector<std::size_t> ij) const = 0;

      virtual Type& operator[](numlib::Vector<std::size_t> ij) = 0;

      // Clone idiom for copying
      virtual std::shared_ptr<Matrix<Type>&> clone() const = 0;

      virtual std::size_t N() const = 0;

      virtual std::size_t M() const = 0;

      virtual void print(std::ostream &out) const = 0;
  }; // class Matrix

} // namespace numlib

#endif 
// MATRIX_H_