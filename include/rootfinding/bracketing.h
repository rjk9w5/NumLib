#ifndef ROOTFINDING_BRACKETING_H_
#define ROOTFINDING_BRACKETING_H_

#include "../typetraits.h"

template <class T, class TFunc>
float_type<T>::T_float 
bisection(TFunc f, numlib::Vector<T> limits);

template <class T, class TFunc>
float_type<T>::T_float 
regulafalsi(TFunc f, numlib::Vector<T> limits);

#endif