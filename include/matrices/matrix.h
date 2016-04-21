/*
 *  matrix.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Base Matrix class for CRTP interface type.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "../vector/vector.h" // numlib::Vector
#include <memory> // std::shared_ptr
#include <ostream> // std::ostream
#include <istream> // std::istream
#include <iomanip> // std::left, std::setw, std::setprecision, std::scientific
#include <initializer_list> // std::initializer_list

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
      Matrix<Type,Form>&
      operator = (
      Matrix<Type,Form> const &src)
      {
        return static_cast<Form<Type>*>(this)->operator=(src);
      }

      ~Matrix() {}

      // Basic Matrix Math operations
      template <template <class> class F>
      Matrix<Type,Form>& operator + (Matrix<Type,F> const &rhs) const
      {
        return static_cast<const Form<Type>*>(this)->operator+(rhs);
      }

      template <template <class> class F>
      Matrix<Type,Form>& operator += (Matrix<Type,F> const &rhs)
      {
        return static_cast<Form<Type>*>(this)->operator+=(rhs);
      }

      template <template <class> class F>
      Matrix<Type,Form>& operator - (Matrix<Type,F> const &rhs) const
      {
        return static_cast<const Form<Type>*>(this)->operator-(rhs);
      }

      template <template <class> class F>
      Matrix<Type,Form>& operator -= (Matrix<Type,F> const &rhs)
      {
        return static_cast<Form<Type>*>(this)->operator-=(rhs);
      }

      template <template<class> class F,template<class> class R>
      Matrix<Type,R>& operator * (Matrix<Type,F> const &rhs) const
      {
        return static_cast<const Form<Type>*>(this)->operator * (rhs);
      }

      Vector<Type> operator * (Vector<Type> const &rhs) const
      {
        return static_cast<const Form<Type>*>(*this) * rhs;
      }

      // Basic Matrix projection, syntax like mat[{i,j}]
      Type operator[](std::initializer_list<std::size_t> ij) const
      {
        return static_cast<const Form<Type>*>(this)->operator[](ij);
      }

      Type& operator[](std::initializer_list<std::size_t> ij)
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

      bool checki(std::size_t const i) const
      {
        return static_cast<const Form<Type>*>(this)->checki(i);
      }

      bool checkj(std::size_t const j) const
      {
        return static_cast<const Form<Type>*>(this)->checkj(j);
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

  namespace output
  {
    constexpr static const int __width__ = 14;
    constexpr static const int __precision__ = 7;
  }
} // namespace numlib

#endif
