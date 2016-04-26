/*
 *  integrate.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Integration base class
 */

#ifndef INGRATOR_INTERFACE_H_
#define INGRATOR_INTERFACE_H_

#include "../vector/vector.h"

namespace numlib
{
  template <class Type, template<class> class Mehtod>
  class Integrator;

  template <class Type, template<class> class Mehtod>
  class Integrator
  {
    public:
      ~Integrator() {}

      template <class T_Function>
      Type 
      integrate(
        numlib::Vector<Type> limits, 
        const int n_pts,
        T_Function f
        ) const
      {
        return static_cast<const Method<Type>*>(this)->integrate(limits,n_pts,f);
      }
  };
} /* numlib */

#endif 
/* INGRATOR_INTERFACE_H_ */