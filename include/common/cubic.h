/* ************************************************************************** *\
 * cubic.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
\* ************************************************************************** */

/*
 *    class: Cubic
 *    brief: Creates and stores data for a cubic equation
 */

/*
 *    Function: Cubic()
 *       Brief: Default Cosntructor
 *         Pre: None
 *        Post: Constructs a Cubic
 */

/*
 *    Function: coeff(numlib::Vector<T>)
 *       Brief: Input vector of coefficients for cubic
 *       Input: coeff vector
 *         Pre: input must be at least of size four
 *        Post: copies input into coefficient vector, only uses first four
 *      return: void
 */

/*
 *    Function: operator ()(T)
 *       Brief: evaluate cubic
 *       Input: value to evaluate at
 *         Pre: Must call coeff first
 *        Post: Evaluates the cubic
 *      return: Result of evaluation
 */

#ifndef CUBIC_H_
#define CUBIC_H_

#include "../vector/vector.h"
#include "exceptions.h"

namespace numlib
{

  template <class T>
  class Cubic
  {
    public:
      Cubic() = default;

      void coeff(numlib::Vector<T> a)
      {
        swap(a_,a);
        return;
      }

      T operator () (T const &x) const
      {
        return a_[0] + a_[1]*x + a_[2]*x*x + a_[3]*x*x*x;
      }

      numlib::Vector<T> get_coeff() const
      {
        return a_;
      }

    private:
      numlib::Vector<T> a_;
  };

}

#endif /* CUBIC_H_ */
