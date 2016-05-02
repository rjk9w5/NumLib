/*
 *  rk4.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Runge-Kutta 4th order
 */

#ifndef ODE_RK4_H_
#define ODE_RK4_H_

#include "../common/typetraits/promote_float.h"
#include <iostream>

template <class T_initv, class T_lims, class TFunc>
numlib::Vector<typename promote_float<T_initv>::type>
rk4_default(const TFunc f, 
            T_initv const &initv, 
            numlib::Vector<T_lims> limits, 
            std::size_t const n);

#include "rk4.hpp"

#endif
