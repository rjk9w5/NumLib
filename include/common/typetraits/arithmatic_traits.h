
#ifndef TYPETRAITS_ARITHMATICTRAITS_H_
#define TYPETRAITS_ARITHMATICTRAITS_H_

#include "../vector/vector.h"

// General float_trait
template <class T>
struct float_trait
{
  typedef T T_float; 
};

template <>
struct float_trait<int>
{
  typedef double T_float;
};

template <>
struct float_trait<char>
{
  typedef double T_float;
};


// Vector handling float_trait structs
template <class T>
struct float_trait<numlib::Vector<T>>
{
  typedef numlib::Vector<T> T_float;
};

template <>
struct float_trait<numlib::Vector<int>>
{
  typedef numlib::Vector<double> T_float;
};

template <>
struct float_trait<numlib::Vector<char>>
{
  typedef numlib::Vector<double> T_float;
};

#endif /* TYPETRAITS_ARITHMATICTRAITS_H_ */