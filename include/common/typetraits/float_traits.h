
#ifndef TYPETRAITS_FLOATTRAITS_H_
#define TYPETRAITS_FLOATTRAITS_H_

#include <cfloat>
#include "promote_float.h"

// General float_traits
template <class T>
struct float_traits
{
  typedef typename promote_float<T>::type type;
  constexpr static const type eps = float_traits<type>::eps;
  constexpr static const type max = float_traits<type>::max;
  constexpr static const type min = float_traits<type>::min;
};

template <>
struct float_traits<float>
{
  typedef float type;
  constexpr static const type eps = FLT_EPSILON;
  constexpr static const type max = FLT_MAX;
  constexpr static const type min = FLT_MIN;
};

template <>
struct float_traits<double>
{
  typedef double type;
  constexpr static const type eps = DBL_EPSILON;
  constexpr static const type max = DBL_MAX;
  constexpr static const type min = DBL_MIN;
};

template <>
struct float_traits<long double>
{
  typedef long double type;
  constexpr static const type eps = LDBL_EPSILON;
  constexpr static const type max = LDBL_MAX;
  constexpr static const type min = LDBL_MIN;
};

#endif /* TYPETRAITS_FLOATTRAITS_H_ */
