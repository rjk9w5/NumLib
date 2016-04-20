/*
 * vector.h
 *
 *  Created on: Feb 5, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Declarations of vector template class and associated
 *              friend functions
 */

/*
 *       class: vector
 *       brief: Template class of an array with automatic memory management.
 */

/*
 *    function: vector()
 *       brief: Default constructor.
 *         pre: None
 *        post: Construct a vector object.
 *      return: None
 */

/*
 *    function: vector(const size_t size)
 *       brief: Constructs an vector of input size.
 *         pre: size must be greater than or equal to 0
 *        post: Constructs an vector of input size.
 *       param: size is an size_t type.
 *      return: None
 */

/*
 *    function: vector(const size_t size, const Ele_T& value)
 *       brief: Size and value constructor.
 *         pre: size must be greater than or equal to 0
 *        post: Constructs an vector of input size with all cells of input
 *              value.
 *       param: size is an size_t type.
 *       param: value is a Ele_T type.
 *      return: None
 */

/*
 *    function: vector(const vector<Ele_T>& src)
 *       brief: Copy constructor
 *         pre: None
 *        post: Constructs an vector object with same values
 *              found in input.
 *       param: vector object to be copied size_to new vector.
 *      return:
 */

/*
 *    function: vector(vector<Ele_T>&& other)
 *       brief: Move constructor
 *         pre: None
 *        post: Moves memory for a new vector object from input.
 *       param: vector object to be moved size_to new vector.
 *      return: None
 */

/*
 *    function: operator=(const vector<Ele_T>& src)
 *       brief: Copy assignment operator.
 *         pre: none
 *        post: Copies data from src to calling object.
 *       param: src is an vector type.
 *      return: calling object.
 */

/*
 *    function: operator=(vector<Ele_T>&& other)
 *       brief: Move assignment operator.
 *         pre: None
 *        post: Moves data from other to calling object.
 *       param: other is an vector type.
 *      return: calling object.
 */

/*
 *    function: ~vector()
 *       brief: Destructor
 *         pre: None
 *        post: Destroys vector object.
 */

/*
 *    function: resize(const size_t size)
 *       brief: Resizes vector while only destroying data in cells with
 *              indices greater than the new size.
 *         pre: size must be greater than or equal to 0
 *        post: Resizes vector but saves data.
 *       param: size to resize to, default=0. (size_t)
 *      return: none
 */

/*
 *    function: reuse(const size_t size)
 *       brief: destroys all existing data and applies a new size.
 *         pre: size must be greater than or equal to 0
 *        post: destroys all existing data and applies a new size.
 *       param: size to resize to, default=0. (size_t)
 *      return: none
 */

/*
 *    function: set_size(const size_t size)
 *       brief: destroys all existing data and sets new size.
 *         pre: size must be greater than or equal to 0
 *        post: destroys all existing data and sets new size.
 *       param: size to resize to. (size_t)
 *      return: none
 */

/*
 *    function: get_size()
 *       brief: returns size.
 *         pre: none
 *        post: returns size.
 *      return: size of vector calling object. (size_t)
 */

/*
 *    function: remove(const size_t i)
 *       brief: removes value at index i if it exists.
 *         pre: size must be greater than or equal to 0 and i must be less than
 *              the size of the calling vector object.
 *        post: value at index i is removed and data is shifted.
 *       param: index i to be removed.
 *      return: none
 */

/*
 *    function: operator[](const size_t i) const
 *       brief: read only access element at index i
 *         pre: size must be greater than or equal to 0 and i must be less than
 *              the size of the calling vector object.
 *        post: returns element value at index i
 *       param: index i to be accessed
 *      return: returns element value at index i
 */

/*
 *    function: operator[](const size_t i)
 *       brief: read-write access element at index i
 *         pre: size must be greater than or equal to 0 and i must be less than
 *              the size of the calling vector object.
 *        post: returns element value at index i
 *       param: index i to be accessed
 *      return: returns element value at index i
 */

/*
 *    function: sort()
 *       brief: Sorts vector calling object
 *         pre: Requires template type Ele_T to have < operator implemented for use
 *              of std::sort
 *        post: Sorts vector
 *      return: none
 */

/*
 *    function: cat()
 *       brief: concatenates two vectors
 *         pre: Both vectors must be of the same element type
 *        post: <Vector1, Vector2> is returned
 *       param: Vector on left side of concatenation
 *       param: Vector on right side of concatenation
 *      return: The concatenated vector
 */

/*
 *    function: dot()
 *       brief: Computes the inner product (dot product) of two input vectors
 *         pre: Both vectors must be of the same size.
 *        post: Scalar value of dot product is computed
 *       param: A vector of size 'n'
 *       param: A vector of size 'n'
 *      return: The scalar dot product of two vectors
 */

/*
 *    function: operator == ()
 *       brief: Check equality of two vectors
 *         pre: Both vectors must be of the same size.
 *        post: Returns true if the two vectors are equal.
 *       param: A vector of size 'n'
 *       param: A vector of size 'n'
 *      return: Returns true if the two vectors are equal.
 */

/*
 *    function: operator != (vector, vector)
 *       brief: Check inequality of two vectors
 *         pre: Both vectors must be of the same size.
 *        post: Returns true if the two vectors are not equal.
 *       param: A vector of size 'n'
 *       param: A vector of size 'n'
 *      return: Returns true if the two vectors are not equal.
 */

/*
 *    function: operator - (vector - vector)
 *       brief: Difference between two vectors
 *         pre: Vectors must be of same size and element type must have -=
 *              operator overloaded.
 *        post: Computes difference between two vectors
 *       param: A vector of size 'n'
 *       param: A vector of size 'n'
 *      return: The vector that is the difference between input vectors
 */

/*
 *    function: operator - (vector -= vector)
 *       brief: Difference between two vectors
 *         pre: Vectors must be of same size.
 *        post: Computes difference between two vectors
 *       param: A vector of size 'n'
 *      return: The difference between vectors as the calling vector
 */

/*
 *    function: operator - (-vector)
 *       brief: Negation of the input vector
 *         pre: None
 *        post: Computes the negation of the vector
 *       param: A vector
 *      return: The negation of the vector
 */

/*
 *    function: operator += (vector += vector)
 *       brief: Sums two vectors, puts result in calling vector object
 *         pre: Vectors must be of same size
 *        post: Computes vector sum
 *       param: Vector of size 'n'
 *      return: Vector sum
 */

/*
 *    function: operator + (vector + vector)
 *       brief: Sums two vectors
 *         pre: Vectors must be of same size
 *        post: Comutes vector sum
 *       param: Vector of size 'n'
 *       param: Vector of size 'n'
 *      return: Vector sum
 */

/*
 *    function: operator * (scalar * vector)
 *       brief: multiplies a scaler to a vector (if the scalar comes first)
 *         pre: Scalar must me the same type as the elements of the vector and
 *              have the '+' operator functionality.
 *        post: Computes element-wise product of scalar and vector.
 *       param: A scalar value (same type as vector elements)
 *       param: A vector
 *      return: Vector of element-wise product of scalar and vector.
 */

/*
 *    function: operator * (vector * scalar)
 *       brief: multiplies a scaler to a vector (if the scalar comes first)
 *         pre: Scalar must me the same type as the elements of the vector and
 *              have the '+' operator functionality.
 *        post: Computes element-wise product of scalar and vector.
 *       param: A scalar value (same type as vector elements)
 *       param: A vector
 *      return: Vector of element-wise product of scalar and vector.
 */

/*
 *    function: operator * (vector * vector)
 *       brief: Computes the inner product of two vectors
 *         pre: Vectors must be of same size
 *        post: Computes the inner product of two vectors
 *       param: Vector of size 'n'
 *       param: Vector of size 'n'
 *      return: inner product
 */

/*
 *    function: operator / (vector / vector)
 *       brief: Computes the element-wise division of two vectors
 *         pre: Vectors must be of same size
 *        post: Computes the element-wise division of two vectors
 *       param: Vector of size 'n'
 *       param: Vector of size 'n'
 *      return: element-wise division vector of size 'n'
 */

/*
 *    function: operator <<
 *       brief: Outputs a vector to screen
 *         pre: none
 *        post: Outputs a vector to screen
 *       param: ostream (such as cout or ofstream)
 *       param: vector
 *      return: input ostream
 */

/*
 *    function: operator >>
 *       brief: Reads in a vector
 *         pre: The vector being read in must have the same number of elements
 *              as the vector being read into.
 *        post: Assigns read values to vector
 *       param: istream (such as cin or ifstream)
 *      return: input istream
 */

/*
 *    function: sum (vector)
 *       brief: Sums elements of a vector
 *         pre: Elements must have '+=' opertor functional
 *        post: Returns sum of vector elements.
 *       param: Vector to have elements summed
 *      return: Sum of vector elements
 */

/*
 *    function: sum()
 *       brief: Sums elements of a vector
 *         pre: Elements must have '+=' opertor functional
 *        post: Returns sum of vector elements.
 *      return: Sum of vector elements
 */

/*
 *    function: sqrt (vector)
 *       brief: Calculates the square root of the elements of a vector
 *         pre: Elements must have sqrt function available
 *        post: Returns vector square roots of elements.
 *       param: Vector to have elements evaluated on
 *      return: vector square roots of elements.
 */

/*
 *    function: abs (vector)
 *       brief: Calculates the absolute value of the elements of a vector
 *         pre: Elements must have abs() function available
 *        post: Returns vector with absolute values of elements.
 *       param: Vector to have elements evaluated on
 *      return: vector with absolute values of elements
 */

/*
 *    function: swap (vector,vector)
 *       brief: Swaps data of two vectors
 *         pre: Must have copy constructor for vector
 *        post: Swaps two vectors
 *       param: Vector reference to be swapped
 *       param: Vector reference to be swapped
 *      return: void
 */

/*
 *    function: ele_swap (size_t, size_t)
 *       brief: Swaps two elements in vector
 *         pre: Ele_T must be compatable with std::swap
 *        post: Swaps two vector elements
 *       param: Vector index to be swapped
 *       param: Vector index to be swapped
 *      return: void
 */

/*
 *    function: allocate ()
 *       brief: Allocates memory for vector
 *         pre: None
 *        post: Allocates memory for vector
 *      return: void
 */

/*
 *    function: deallocate ()
 *       brief: Deallocates memory for vector
 *         pre: None
 *        post: Deallocates memory for vector
 *      return: void
 */

/*
 *    function: checki (size_t)
 *       brief: Checks if index is valid
 *         pre: None
 *        post: Checks if index is valid
 *       param: Vector index to be checked
 *      return: true if valid else false
 */

// TODO: Figure out how to comment about type-traits. Not used in assignment so
//       not commented here.

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "../common/exceptions.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <utility>
#include <cmath>
#include <fstream>
#include <initializer_list>

namespace numlib
{
  typedef unsigned long int index;
  // VECTOR DECLARATION
  template <class Ele_T>
  class Vector;

  // GLOBAL FUNCTION DECLARATIONS
  template <class Ele_T>
  void swap(Vector<Ele_T> &v1, Vector<Ele_T> &v2);

  template <class Ele_T>
  bool operator == (const Vector<Ele_T>& lhs, const Vector<Ele_T>& rhs);

  template <class Ele_T>
  bool operator != (const Vector<Ele_T>& lhs, const Vector<Ele_T>& rhs);

  template <class Ele_T>
  Vector<Ele_T> cat(const Vector<Ele_T>& a1, const Vector<Ele_T>& a2);

  template <class Ele_T>
  std::ostream& operator << (std::ostream& out, const Vector<Ele_T>& vec);

  template <class Ele_T>
  std::istream& operator >> (std::istream& in, Vector<Ele_T>& vec);

  template <class Ele_T>
  Vector<Ele_T> operator * (const Ele_T& C, const Vector<Ele_T>& v2);

  template <class Ele_T>
  Vector<Ele_T> operator + (const Vector<Ele_T>& v1, const Vector<Ele_T>& v2);

  template <class Ele_T>
  Vector<Ele_T> operator - (const Vector<Ele_T>& v1, const Vector<Ele_T>& v2);

  template <class Ele_T>
  Vector<Ele_T> operator - (const Vector<Ele_T>& vec);

  template <class Ele_T>
  Ele_T sum(const Vector<Ele_T>& vec);

  template <class Ele_T>
  Ele_T dot(const Vector<Ele_T>& v1, const Vector<Ele_T>& v2);

  // VECTOR CLASS
  template <class Ele_T>
  class Vector
  {
    public:

      Vector();
      Vector(const std::size_t size);
      Vector(std::size_t const size, Ele_T const &value);
      Vector<Ele_T>& operator = (Vector<Ele_T> src);
      Vector(const Vector<Ele_T>& src);
      Vector(Vector<Ele_T> &&other);
      Vector(std::initializer_list<Ele_T> const &l);
      ~Vector();

      // UTILITIES
      void resize(std::size_t const size=0);
      void reuse(std::size_t const size=0);
      void clear();
      void set_size(const size_t size);
      size_t get_size() const {return size_;}
      void remove(const size_t i);
      const Ele_T& operator[](const size_t i) const;
      Ele_T& operator[](const size_t i);
      Vector<Ele_T>& sort();
      Ele_T* begin() const;
      Ele_T* end() const;
      int find(const Ele_T& val);
      void ele_swap(std::size_t const i1, std::size_t const i2);

      // MATH
      Ele_T sum() const;
      Ele_T dot(const Vector<Ele_T>& vec) const;
      Vector<Ele_T>& operator += (const Vector<Ele_T>& vec);
      Vector<Ele_T>& operator -= (const Vector<Ele_T>& vec);
      Vector<Ele_T> operator * (const Ele_T& C) const;
      Ele_T operator * (const Vector<Ele_T>& v2) const;
      Vector<Ele_T> operator / (const Ele_T& C) const;
      Vector<Ele_T> operator / (const Vector<Ele_T>& v2) const;

      friend Vector<Ele_T> operator+ <> (const Vector<Ele_T>& v1, const Vector<Ele_T>& v2);
      friend Vector<Ele_T> operator- <> (const Vector<Ele_T>& v1, const Vector<Ele_T>& v2);
      friend Vector<Ele_T> operator- <> (const Vector<Ele_T>& vec);

      // FRIENDS
      friend Vector<Ele_T> cat <> (const Vector<Ele_T>& a1, const Vector<Ele_T>& a2);
      friend bool operator == <> (const Vector<Ele_T>& lhs, const Vector<Ele_T>& rhs);
      friend bool operator != <> (const Vector<Ele_T>& lhs, const Vector<Ele_T>& rhs);
      friend std::ostream& operator << <> (std::ostream& out, const Vector<Ele_T>& vec);
      friend std::istream& operator >> <> (std::istream& in, Vector<Ele_T>& vec);
      friend void swap <> (Vector<Ele_T> &v1, Vector<Ele_T> &v2);

    private:
      void allocate();
      void deallocate();
      bool checki(std::size_t i) const {return i<size_;}
      index size_;
      Ele_T* data_;
  };

} // numlib namespace

// MICELANIOUS (No comments because not used!)
template <class Ele_T>
struct isVector
{
  static const bool value = false;
};

template <class Ele_T>
struct isVector<numlib::Vector<Ele_T>>
{
  static const bool value = true;
};

// TODO: Overload additional math functions from <cmath>. Also move to a
//       different file because this thing is crazy!
template <class Ele_T>
numlib::Vector<Ele_T> sqrt(const numlib::Vector<Ele_T>& vec);

template <class Ele_T>
numlib::Vector<Ele_T> abs(const numlib::Vector<Ele_T>& vec);

#include "vectorI.hpp"
#include "vectorG.hpp"

#endif /* VECTOR_HPP_ */
