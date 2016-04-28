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
 *    Function: CSpline(oonm::Vector<oonm::Coordinate<T>>)
 *       Brief: Cosntructor from set of data points
 *       Input: Data set used to generate curve fit
 *         Pre: None
 *        Post: Constructs a CSpline from input data
 */

/*
 *    Function: points(oonm::Vector<oonm::Coordinate<T>>)
 *       Brief: Calculates curve fit from set of data points
 *       Input: Data set used to generate curve fit
 *         Pre: None
 *        Post: Calculates a cubic spline curve Fit from input data
 *      return: void
 */

/*
 *    Function: operator ()(oonm::Vector<oonm::Coordinate<T>>)
 *       Brief: Calculates curve fit from set of data points
 *         Pre: Must call points or Vector<Coordinate> constructor first
 *        Post: Evaluates the cubic spline curve Fit from input data
 *      return: Result of evaluation
 */

#ifndef CSPLINE_H_
#define CSPLINE_H_

#include "exceptions.h"
#include "cubic.h"
#include "pair.h"
#include "coord.h"
#include "matrix_tridiag.h"
#include "linearsystem_solvers.h"
#include "vector.h"
#include <fstream>
#include <cstring>

namespace oonm
{
  template <class T>
  class CSpline
  {
    public:
      CSpline() = default;
      CSpline(oonm::Vector<oonm::Coordinate<T>> const &pts);

      void points(oonm::Vector<oonm::Coordinate<T>> const &pts);

      T operator ()(T const &x) const;

      void write_octave(std::string fname);

    private:
      std::size_t get_cubic(T const &x) const;
      T lx_;
      oonm::Vector<oonm::Pair<double,oonm::Cubic<double>>> cspline_;
  };
} // oonm

#include "csplineI.hpp"

#endif /* CSPLINE_H_ */
