/*
 *  abash.h
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Adams-Bashforth type methods
 */

#ifndef ODE_ABASH_H_
#define ODE_ABASH_H_

#include "../typetraits/arithmatic_traits.h"
#include "rk4.h"

template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
abash_2(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n);

template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
abash_3(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n);

#include "abash.hpp"

#endif
