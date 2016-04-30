#ifndef ROOTFINDING_SLOPING_H_
#define ROOTFINDING_SLOPING_H_

#include "../typetraits.h"

template <class T, class TFunc>
float_type<T>::T_float 
secant(TFunc f, numlib::Vector<T> limits);

#include "sloping.hpp"

#endif