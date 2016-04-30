
#ifndef TYPETRAITS_PROMOTEFLOAT_H_
#define TYPETRAITS_PROMOTEFLOAT_H_

#include "../../vector/vector.h"

// General promote_float that takes a float type
template <class T>
struct promote_float
{
  typedef T type;
};

// Integer types
template <>
struct promote_float<int>
{
  typedef double type;
};

template <>
struct promote_float<char>
{
  typedef double type;
};

template <>
struct promote_float<short>
{
  typedef float type;
};

template <>
struct promote_float<long>
{
  typedef double type;
};

template <>
struct promote_float<long long>
{
  typedef long double type;
};

// // Unsigned Integer types
// template <>
// struct promote_float<unsigned int>
// {
//   typedef unsigned double type;
// };
//
// template <>
// struct promote_float<unsigned char>
// {
//   typedef unsigned double type;
// };
//
// template <>
// struct promote_float<unsigned short>
// {
//   typedef unsigned float type;
// };
//
// template <>
// struct promote_float<unsigned long>
// {
//   typedef unsigned double type;
// };
//
// template <>
// struct promote_float<unsigned long long>
// {
//   typedef unsigned long double type;
// };

// Vector handling promote_float struct
template <class T>
struct promote_float<numlib::Vector<T>>
{
  typedef numlib::Vector<typename promote_float<T>::type> type;
};

#endif /* TYPETRAITS_PROMOTEFLOAT_H_ */
