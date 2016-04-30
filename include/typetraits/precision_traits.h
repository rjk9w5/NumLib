#ifndef TYPETRAITS_PRECISIONTRAITS_H_
#define TYPETRAITS_PRECISIONTRAITS_H_

#include <climits>
#include <cfloat>

template <class T>
struct machine_precision
{
  typedef T type;
};

template <>
struct machine_precision<int>
{
  typedef int type;
  type max = INT_MAX;
  type min = INT_MIN;
};

template <>
struct machine_precision<short>
{
  typedef short type;
  type max = SHRT_MAX;
  type min = SHRT_MIN;
};

template <>
struct machine_precision<long>
{
  typedef long type;
  type max = LONG_MAX;
  type min = LONG_MIN;
};

template <>
struct machine_precision<long long>
{
  typedef long long type;
  type max = LLONG_MAX;
  type min = LLONG_MIN;
};

template <>
struct machine_precision<float>
{
  typedef float type;
  type eps = FLT_EPSILON;
  type max = FLT_MAX;
  type min = FLT_MIN;
};

template <>
struct machine_precision<double>
{
  typedef double type;
  type eps = DBL_EPSILON;
  type max = DBL_MAX;
  type min = DBL_MIN;
};

template <>
struct machine_precision<long double>
{
  typedef long double type;
  type eps = LDBL_EPSILON;
  type max = LDBL_MAX;
  type min = LDBL_MIN;
};

#endif /* TYPETRAITS_PRECISIONTRAITS_H_ */