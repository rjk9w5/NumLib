/* ************************************************************************** *\
 * istream_utility.h
 *
 *  Created on: Mar 12, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
\* ************************************************************************** */
#ifndef ISTREAM_UTILITY_H_
#define ISTREAM_UTILITY_H_

#include <istream>
#include "exceptions.h"

/*
 *    function: checkIstream()
 *       brief: Checks if std::istream is still reading correctly
 *       input: istream to be checked
 *         pre: None
 *        post: if the istream is bad, it will throw an oonm::Exception type
 *      return: void
 */

namespace numlib
{
  bool checkIstream(std::istream& in);
}

#endif /* ISTREAM_UTILITY_H_ */
