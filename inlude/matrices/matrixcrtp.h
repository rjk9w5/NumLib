/*
 *  matrixcrtp.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Base MatrixCRTP class for CRTP interface type.
 */

#ifndef MATRIXCRTP_H_
#define MATRIXCRTP_H_

#include "matrix.h"
#include <iomanip>

namespace numlib
{
  template <class Type, template<class> class Form>
  class MatrixCRTP;

  template <class Type, template<class> class Form>
  std::ostream&
  operator << (
    std::ostream &out,
    MatrixCRTP<Type,Form> const &mat);

  template <class Type, template<class> class Form>
  class MatrixCRTP: public virtual Matrix<Type>
  {
    public:
      // MatrixCRTP<Type,Form>&
      // operator = (
      //   MatrixCRTP<Type,Form> const &src)
      // {
      //   std::cout << "op = from MatrixCRTP<Type,Form>\n";
      //   return this->operator=(static_cast<const Form<Type>&>(src));
      // }

      // Basic MatrixCRTP Math operations
      virtual Matrix<Type>& operator + (Matrix<Type> const &rhs) const
      {
        std::shared_ptr<MatrixCRTP<Type,Form>> ret = clone();
        return static_cast<Form<Type>*>(ret.get())->operator+=(rhs);
      }

      virtual Matrix<Type>& operator += (Matrix<Type> const &rhs)
      {
        return static_cast<Form<Type>*>(this)->operator+=(rhs);
      }

      // template <class F>
      // Form<Type> operator - (MatrixCRTP<F> const &rhs) const
      // {
      //   return static_cast<const Form&>(*this) - rhs;
      // }
      //
      // template <class F>
      // Form<Type> operator * (MatrixCRTP<F> const &rhs) const
      // {
      //   return static_cast<const Form&>(*this) * rhs;
      // }
      //
      // Form<Type> operator * (Vector<Type> const &rhs) const
      // {
      //   return static_cast<const Form&>(*this) * rhs;
      // }

      // Basic MatrixCRTP projection, syntax like mat[{i,j}]
      Type operator[](numlib::Vector<std::size_t> ij) const
      {
        return static_cast<const Form<Type>*>(this)->operator[](ij);
      }

      Type& operator[](numlib::Vector<std::size_t> ij)
      {
        return static_cast<Form<Type>*>(this)->operator[](ij);
      }

      // Clone idiom for copying
      std::shared_ptr<Matrix<Type>&> clone() const
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

      virtual void print(std::ostream &out) const
      {
        static_cast<const Form<Type>*>(this)->print(out);
      }
  }; // class MatrixCRTP

  template <class Type, template<class> class Form>
  std::ostream&
  operator << (
    std::ostream &out,
    MatrixCRTP<Type,Form> const &mat)
  {
    mat.print(out);
    return out;
  }
} // namespace numlib

#endif 
// MATRIXCRTP_H_
