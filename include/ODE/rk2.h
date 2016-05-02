/*
 *  rk2.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Runge-Kutta 2nd order
 */

#ifndef ODE_RK2_H_
#define ODE_RK2_H_

#include "../common/typetraits/promote_float.h"

template <class T_initv, class T_lims, class TFunc>
numlib::Vector<typename promote_float<T_initv>::type>
rk2_heun(const TFunc f, 
            T_initv const &initv, 
            numlib::Vector<T_lims> limits, 
            std::size_t const n);

template <class T_initv, class T_lims, class TFunc>
numlib::Vector<typename promote_float<T_initv>::type>
rk2_modEuler(const TFunc f, 
            T_initv const &initv, 
            numlib::Vector<T_lims> limits, 
            std::size_t const n);

template <class T_initv, class T_lims, class TFunc>
numlib::Vector<typename promote_float<T_initv>::type>
rk2_midEuler(const TFunc f, 
            T_initv const &initv, 
            numlib::Vector<T_lims> limits, 
            std::size_t const n);

#include "rk2.hpp"

#endif
