#ifndef TYPETRAITS_INTTRAITS_H_
#define TYPETRAITS_INTTRAITS_H_

#include <climits>

template <class T>
struct int_traits
{
};

template <>
struct int_traits<int>
{
  typedef int type;
  constexpr type max = INT_MAX;
  constexpr type min = INT_MIN;
};

template <>
struct int_traits<short>
{
  typedef short type;
  constexpr type max = SHRT_MAX;
  constexpr type min = SHRT_MIN;
};

template <>
struct int_traits<long>
{
  typedef long type;
  constexpr type max = LONG_MAX;
  constexpr type min = LONG_MIN;
};

template <>
struct int_traits<long long>
{
  typedef long long type;
  constexpr type max = LLONG_MAX;
  constexpr type min = LLONG_MIN;
};

#endif /* TYPETRAITS_INTTRAITS_H_ */
