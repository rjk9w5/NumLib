/*
 * qr_orthonormal.h
 *
 *  Created on: Feb 24, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
 */

/*
 *       class: QR_decomp
 *       brief: Functor class for QR decomposition using the modified
 *              Gram-Schmidt process.
 */

/*
 *    function: operator()
 *       brief: Evaluates the QR decomposition of a given vector set
 *         pre: Vector set must contain a set of more than zero equally
 *              sized vectors of size greater than zero.
 *        post: Returns an array of vector sets. The first element of the array
 *              is the Q vector set and the second element is the R vector set.
 *              TODO: Overload to work with matrix classes
 *      return: Returns an array of vector sets. The first element of the array
 *              is the Q vector set and the second element is the R vector set.
 */

#ifndef QR_DECOMP_H_
#define QR_DECOMP_H_

#include "../vector/vector.h"
#include "../matrices/matrices.h"
#include "../common/exceptions.h"
#include <cmath>
#include <iostream>

namespace numlib
{
  template <class Type>
  class QR_OrthoNormal
  {
    public:
      void operator() (
        numlib::Dense<Type> const &A,
        numlib::Dense<Type> &Q,
        numlib::UpperTriangle<Type> &R);
    private:
      numlib::Vector<Type> proj(
        numlib::Vector<Type> const &e,
        numlib::Vector<Type> const &a);

      void unitize(numlib::Vector<Type> &u2e);

      Dense<Type>
      makeQ(
        Vector<Vector<Type>> const &e);

      UpperTriangle<Type>
      makeR(
        Vector<Vector<Type>> const &e,
        Vector<Vector<Type>> const &a);
  };
}
#include "qr_orthonormal.hpp"


#endif /* QR_DECOMP_H_ */
