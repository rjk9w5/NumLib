/* ************************************************************************** *\
 * cspline.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
\* ************************************************************************** */

/*
 *    class: CSpline
 *    brief: Creates and stores data for a cbuic spline curve fit
 */

/*
 *    Function: CSpline()
 *       Brief: Default Cosntructor
 *         Pre: None
 *        Post: Constructs a CSpline
 */

/*
 *    Function: CSpline(numlib::Vector<numlib::Coordinate<T>>)
 *       Brief: Cosntructor from set of data points
 *       Input: Data set used to generate curve fit
 *         Pre: None
 *        Post: Constructs a CSpline from input data
 */

/*
 *    Function: points(numlib::Vector<numlib::Coordinate<T>>)
 *       Brief: Calculates curve fit from set of data points
 *       Input: Data set used to generate curve fit
 *         Pre: None
 *        Post: Calculates a cubic spline curve Fit from input data
 *      return: void
 */

/*
 *    Function: operator ()(numlib::Vector<numlib::Coordinate<T>>)
 *       Brief: Calculates curve fit from set of data points
 *         Pre: Must call points or Vector<Coordinate> constructor first
 *        Post: Evaluates the cubic spline curve Fit from input data
 *      return: Result of evaluation
 */

#ifndef CSPLINE_H_
#define CSPLINE_H_

#include "../common/exceptions.h"
#include "../common/cubic.h"
#include "../common/pair.h"
#include "../common/coord.h"
#include "../matrices/tridiagonal.h"
#include "../linearsystems/linearsystem_solvers.h"
#include "../vector/vector.h"
#include <fstream>
#include <cstring>

namespace numlib
{
  template <class T>
  class CSpline
  {
    public:
      CSpline() = default;
      CSpline(numlib::Vector<numlib::Coordinate<T>> const &pts);

      void points(numlib::Vector<numlib::Coordinate<T>> const &pts);
      void points_clamped(numlib::Vector<numlib::Coordinate<T>> const &pts, T const &fp0, T const &fpN);

      T operator ()(T const &x) const;

      void write_octave(std::string fname);

    private:
      std::size_t get_cubic(T const &x) const;
      T lx_;
      numlib::Vector<numlib::Pair<double,numlib::Cubic<double>>> cspline_;
  };
} // numlib

#include "csplineI.hpp"

#endif /* CSPLINE_H_ */
