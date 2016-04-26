/*
 *  trapezoidal.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Trapezoidal integration class
 */

#ifndef INGRATOR_INTERFACE_H_
#define INGRATOR_INTERFACE_H_

#include "integrate.h"

namespace numlib
{
  template <class Type>
  class Trapz;

  template <class Type>
  class Trapz: public Integrator<Type, Trapz>
  {
    public:
      ~Trapz() {}
      
      template <class T_Function>
      Type 
      integrate(
        numlib::Vector<Type> limits, 
        const int n_pts,
        T_Function f
        )
      {
        Type sum = 0;
        Type h = (limits[1] - limits[0])/(n_pts-1);

        for(int i=0; i<n_pts; ++i)
          sum+=(f(limits[0] + i*h) + f(limits[0] + (i+i)*h))/2;

        return sum*((limits[1] - limits[0])/(n_pts));
      }
  };
} /* numlib */

#endif
/* INGRATOR_INTERFACE_H_ */