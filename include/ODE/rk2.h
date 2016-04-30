/*
 *  rk2.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Runge-Kutta 2nd order
 */

#ifndef ODE_RK2_H_
#define ODE_RK2_H_

#include "../typetraits/arithmatic_traits.h"

template <class T, class TFunc>
numlib::Vector<typename float_trait<T>::T_float> 
rk2_heun(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n);

template <class T, class TFunc>
numlib::Vector<typename float_trait<T>::T_float> 
rk2_modEuler(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n);

template <class T, class TFunc>
numlib::Vector<typename float_trait<T>::T_float> 
rk2_midEuler(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n);

#include "rk2.hpp"

#endif