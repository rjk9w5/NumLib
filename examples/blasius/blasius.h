#include "../../include/vector/vector.h"
#include "../../include/ODE/rk4.h"
#include "../../include/ODE/rk2.h"
#include "../../include/rootfinding/sloping.h"

numlib::Vector<numlib::Vector<double>>
blasius(
  const double ubound, 
  const int n);