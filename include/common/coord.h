/* ************************************************************************** *\
 * coord.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
\* ************************************************************************** */

/*
 *    Function: Coordinate()
 *       Brief: Default constructor
 *         Pre: None
 *        Post: Constructs a Coordinate
 */

/*
 *    Function: Coordinate(T, T)
 *       Brief: Cosntructor with inputs for x and y
 *       Input: x value
 *       Input: y value
 *         Pre: None
 *        Post: Constructs a Coordinate of <i=x,j=y,k=0>
 */

/*
 *    Function: Coordinate(T, T,T)
 *       Brief: Cosntructor with inputs for x and y and z
 *       Input: x value
 *       Input: y value
 *       Input: z value
 *         Pre: None
 *        Post: Constructs a Coordinate of <i=x,j=y,k=z>
 */

/*
 *    Function: operator < (Coordinate) const
 *       Brief: Comparison operators between Coordinates
 *       Input: Coordinate type to compare against
 *         Pre: Type T must be overloaded for use of < operator
 *        post: returns bool result of comparing x, if equal the y, if equal
 *              then z
 *      return: bool result of comparing x, if equal the y, if equal then z
 */

/*
 *    Function: x(), y(), z() or i(), j(), k()
 *       Brief: Read access to coordinate data
 *         Pre: None
 *        Post: Returns a copy of data in Coordinate
 *      return: a copy of data in Coordinate
 */

/*
 *    Function: x(T), y(T), z(T) or i(T), j(T), k(T)
 *       Brief: Write access to coordinate data
 *       Input: value to write to coordinate
 *         Pre: None
 *        Post: writes input to coordinate data
 *      return: void
 */

#ifndef COORD_H_
#define COORD_H_

#include "pair.h"
#include <ostream>

namespace numlib
{
  template <class T>
  class Coordinate;

  template <class T>
  std::ostream&
  operator << (
      std::ostream& out,
      numlib::Coordinate<T> const &crd);

  template <class T>
  class Coordinate
  {
    private:
      T i_,j_,k_;
    public:
      Coordinate() = default;

      Coordinate(
          T const &x,
          T const &y): i_(x), j_(y) {}

      Coordinate(
          T const &x,
          T const &y,
          T const &z): i_(x), j_(y), k_(z) {}

      bool operator < (Coordinate const &c)
      {
        return (i_ < c.i_?1:(c.i_ < i_?0:(j_ < c.j_?1:0)));
      }

      T x() const {return i_;}
      void x(T const &i) {i_ = i;}

      T i() const {return i_;}
      void i(T const &i) {i_ = i;}

      T y() const {return j_;}
      void y(T const &i) {j_ = i;}

      T j() const {return j_;}
      void j(T const &i) {j_ = i;}

      T z() const {return k_;}
      void z(T const &i) {k_ = i;}

      T k() const {return k_;}
      void k(T const &i) {k_ = i;}
  };

  template <class T>
  std::ostream&
  operator << (
      std::ostream& out,
      numlib::Coordinate<T> const &crd)
  {
    out << crd.x() << ' ' << crd.y();

    if(crd.z()!=0)
      out << ' ' << crd.z();

    return out;
  }

}


#endif /* COORD_H_ */
