/*
 *  test.cpp
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Test integration
 */

#include <iostream>
#include <fstream>
#include <functional>
#include <cmath>
#include <iomanip>
#include "../vector/vector.h"
#include "integrators.h"

using namespace numlib;

double func1(const double x);

int main(int argc, char** args)
{
  if(argc) std::cout << args[0] << '\n';

  Vector<double> limits = {0,acos(-1)};
  double solution;
  std::ofstream fout;
  fout.open("results.m");

  std::cout << "\n=== Part 1 ===\n";

  auto f1 = [](const double x)
  {
    return -x*cos(x) + sin(x);
  };

  double p1a = f1(limits[1]) - f1(0);

  fout << "actual = " << std::setprecision(19) << p1a << ";\n";

  std::cout << "\n=== Trapezoidal Method ===\n";
  fout << "trap = [";
  for(int i=2; i<=40; i+=2)
  {
    solution = trapz(limits, i, std::function<double(double)>(func1));
    std::cout << "n = " << i <<  ": I = " << std::setprecision(19) << solution << "\n";
    fout << std::setprecision(19) << solution << (i!=40?"; \n":"");
  }
  fout << "];\n\n";

  std::cout << "\n=== Simpson's 1/3 ===\n";
  fout << "simp3 = [";
  for(int i=2; i<=40; i+=2)
  {
    solution = simpson3(limits, i, std::function<double(double)>(func1));
    std::cout << "n = " << i <<  ": I = " << std::setprecision(19) << solution << "\n";
    fout << std::setprecision(19) << solution << (i!=40?"; \n":"");
  }
  fout << "];\n\n";
  
  fout.close();

  std::cout << "\n=== Part 2 ===\n";

  std::cout << "\n=== Gauss Quadurature (3) ===\n";
  solution = gaussQuad3(limits, std::function<double(double)>(func1));
  std::cout << "I = " << std::setprecision(19) << solution << '\n';

  std::cout << "\n=== Gauss Quadurature (4) ===\n";
  solution = gaussQuad4(limits, std::function<double(double)>(func1));
  std::cout << "I = " << std::setprecision(19) << solution << '\n';

  std::function<double(double,double)> func2 = [](const double x, const double y) -> double
  {
    return x*y*exp(y-x);
  };

  std::cout << "\n=== Part 3 ===\n";
  auto f = [](const double x)
  {
    return -x*exp(-x) - exp(-x) + 0.5*(x*exp(0.5 - x) + exp(0.5 - x));
  };

  double p2a = f(0.5) - f(0.0);
  limits = {0,0.5};

  solution = simpson3(limits, 2, 
    [&](const double x)->double
    {
      return simpson3(limits, 2, 
        [&](const double y)->double
        {
          return func2(x,y);
        });
    });
  std::cout << "\n=== Simpson's 1/3 ===\n";
  std::cout << "I = " << std::setprecision(19) << solution << '\n';
  std::cout << "Error: " << fabs(p2a - solution)/fabs(p2a)*100.0 << "% \n";

  solution = gaussQuad3(limits, 
    [&](const double x)->double
    {
      return gaussQuad3(limits, 
        [&](const double y)->double
        {
          return func2(x,y);
        });
    });
  std::cout << "\n=== Gauss Quadurature (3) ===\n";
  std::cout << "I = " << std::setprecision(19) << solution << '\n';
  std::cout << "Error: " << fabs(p2a - solution)/fabs(p2a)*100.0 << "% \n";

  std::cout << "\n=== Part 4 ===\n";
  limits = {0,1};
  std::function<double(double)> func3 = [](const double x)
  {
    return sqrt(1 - x*x)*x*x;
  };

  std::cout << "\n=== Simpson's 1/3 ===\n";
  solution = simpson3(limits, 2, func3);
  std::cout << "I = " << std::setprecision(19) << solution << "\n";

  std::cout << "\n=== Gauss Quadurature (3) ===\n";
  solution = gaussQuad3(limits, func3);
  std::cout << "I = " << std::setprecision(19) << solution << '\n';

  std::function<double(double)> func4 = [](const double x)
  {
    return sqrt(1 - x*x)*x;
  };

  std::function<double(double)> func5 = [](const double x)
  {
    return sqrt(1 - x*x);
  };

  // Part 4.b
  std::cout << "\n=== System of equations for Part 4.b ===\n";
  solution = gaussQuad4(limits, func5);
  std::cout << std::setprecision(19) << solution << " = w0 + w1 + w2\n";

  solution = gaussQuad4(limits, func4);
  std::cout << std::setprecision(19) << solution << " = w1*0.5 + w2\n";

  solution = gaussQuad4(limits, func3);
  std::cout << std::setprecision(19) << solution << " = w1*0.25 + w2\n";

  std::cout << "\n**Note, Gauss Quadurature 4 was used to do the integral\n"
            << "because doing it by hand was not enjoyable...\n\n";

  return 0;
}

double func1(const double x)
{
  return x*sin(x);
}