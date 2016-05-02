#ifndef ROOTFINDING_SLOPING_H_
#define ROOTFINDING_SLOPING_H_

#include "../common/convergence.h"
// #include "../derivatives/derivatives.h"
#include <iostream>

template <class T, class TFunc>
typename promote_float<T>::type
secant(TFunc f, T x0, T x1);

// template <class T, class TFunc>
// typename promote_float<T>::type
// modsecant(TFunc f, T x0, T x1, T x2);

#include "sloping.hpp"

#endif
