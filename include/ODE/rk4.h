/*
 *  rk4.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Runge-Kutta 4th order
 */

#ifndef ODE_RK4_H_
#define ODE_RK4_H_

#include "../typetraits/arithmatic_traits.h"

template <class T, class TFunc>
numlib::Vector<typename float_trait<T>::T_float> 
rk4_default(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n);

#include "rk4.hpp"

#endif