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
#include <iomanip>

namespace numlib
{
  template <class Type, template<class> class Form>
  class Matrix;

  template <class Type, template<class> class Form>
  std::ostream&
  operator << (
    std::ostream &out,
    Matrix<Type,Form> const &mat);

  template <class Type, template<class> class Form>
  class Matrix
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
      template <template <class> class F>
      Matrix<Type,Form>& operator + (Matrix<Type,F> const &rhs) const
      {
        std::shared_ptr<Matrix<Type,Form>> ret = clone();
        return static_cast<Form<Type>*>(ret.get())->operator+=(rhs);
      }

      template <template <class> class F>
      Matrix<Type,Form>& operator += (Matrix<Type,F> const &rhs)
      {
        return static_cast<Form<Type>*>(this)->operator+=(rhs);
      }

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
      Type operator[](numlib::Vector<std::size_t> ij) const
      {
        return static_cast<const Form<Type>*>(this)->operator[](ij);
      }

      Type& operator[](numlib::Vector<std::size_t> ij)
      {
        return static_cast<Form<Type>*>(this)->operator[](ij);
      }

      // Clone idiom for copying
      std::shared_ptr<Matrix<Type, Form>> clone() const
      {
        return static_cast<const Form<Type>*>(this)->clone();
      }

      std::size_t N() const
      {
        return static_cast<const Form<Type>*>(this)->N();
      }

      std::size_t M() const
      {
        return static_cast<const Form<Type>*>(this)->M();
      }
  }; // class Matrix

  template <class Type, template<class> class Form>
  std::ostream&
  operator << (
    std::ostream &out,
    Matrix<Type,Form> const &mat)
  {
    static_cast<const Form<Type>*>(&mat)->print(out);
    return out;
  }
} // namespace numlib

#endif
