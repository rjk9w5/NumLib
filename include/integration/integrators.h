#ifndef INTEGRATORS_FUNCTIONS_H_
#define INTEGRATORS_FUNCTIONS_H_

template <class T_Function>
double trapz(numlib::Vector<double> limits, int n_pts, T_Function f);

template <class T_Function>
double simpson3(numlib::Vector<double> limits, int n_pts, T_Function f);

template <class T_Function>
double gaussQuad3(numlib::Vector<double> limits, T_Function f);

template <class T_Function>
double gaussQuad4(numlib::Vector<double> limits, T_Function f);

#include "integrators.hpp"

#endif