/* ************************************************************************** *\
 * istream_utilityI.cpp
 *
 *  Created on: Mar 12, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
\* ************************************************************************** */


#include "istream_utility.h"

bool numlib::checkIstream(std::istream& in)
{
  bool check(in.eof() || in.bad());
  if(in.eof() || in.bad())
    throw numlib::FatalError("In std::istream: Stream not good!");

  return !check;
}
