#ifndef COMMON_CONVERGENCE_H_
#define COMMON_CONVERGENCE_H_

#include <cmath>
#include "typetraits/float_traits.h"
#include "typetraits/promote_float.h"

namespace numlib
{
  namespace converge
  {
    template <class T>
    struct tolerance
    {
      typedef typename float_traits<T>::type ftype;
      constexpr static const ftype __tolerance__ = float_traits<ftype>::eps;

      ftype HYPER_FINE=1*__tolerance__;
      ftype SUPER_FINE=2*__tolerance__;
      ftype FINE=5*__tolerance__;
      ftype NORMAL=10*__tolerance__;
      ftype CORSE=100*__tolerance__;
      ftype SUPER_CORSE=1000*__tolerance__;
      ftype HYPER_CORSE=10000*__tolerance__;
    };
  }
}

#endif
