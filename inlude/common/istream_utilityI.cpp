/* ************************************************************************** *\
 * istream_utilityI.cpp
 *
 *  Created on: Mar 12, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: 
\* ************************************************************************** */


#include "istream_utility.h"

void oonm::checkIstream(std::istream& in)
{
  if(in.eof() || in.bad())
    throw oonm::FatalError("In std::istream: Stream not good!");

  return;
}
