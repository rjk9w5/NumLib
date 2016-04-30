#ifndef COMMON_CONVERGENCE_H_
#define COMMON_CONVERGENCE_H_

#include <cmath>
#include "../typetraits.h"

namespace numlib
{
  namespace converge
  {
    template <class T>
    T __tolerance__ = machine_precision<T>::eps;

    template <class T>
    struct tolerance 
    {
      typedef typename float_traits<T>::float_type ftype; 
      ftype HYPER_FINE=1*__tolerance__<ftype>;
      ftype SUPER_FINE=2*__tolerance__<ftype>;
      ftype FINE=5*__tolerance__<ftype>;
      ftype NORMAL=10*__tolerance__<ftype>;
      ftype CORSE=100*__tolerance__<ftype>;
      ftype SUPER_CORSE=1000*__tolerance__<ftype>;
      ftype HYPER_CORSE=10000*__tolerance__<ftype>;
    };
  }
}

#endif