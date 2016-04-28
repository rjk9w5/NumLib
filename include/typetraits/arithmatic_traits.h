
#ifndef TYPETRAITS_ARITHMATICTRAITS_H_
#define TYPETRAITS_ARITHMATICTRAITS_H_

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

#endif /* TYPETRAITS_ARITHMATICTRAITS_H_ */