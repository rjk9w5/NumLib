#include "blasius.h"
#include <iostream>

numlib::Vector<numlib::Vector<double>> 
blasius(
  const double ubound, 
  const int n)
{
  numlib::Vector<numlib::Vector<double>> solution;

  auto fode = [](const double dummy, const numlib::Vector<double> z)
  {
    return numlib::Vector<double>({z[1],z[2],-0.5*z[0]*z[2]});
  };

  auto f = [&](const double x) -> double
  {
    solution = rk2_heun(fode, 
                        numlib::Vector<double>({0,0,x}), 
                        numlib::Vector<double>({0.0,ubound}), 
                        n);
    return solution[n][1]-1;
  };

  secant(f,0.3,0.4);

  return solution;
}