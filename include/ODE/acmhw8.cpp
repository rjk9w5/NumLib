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
#include "rk2.h"
#include "rk4.h"

using namespace numlib;

int main(int argc, char** args)
{
  if(argc) std::cout << args[0] << '\n';

  Vector<double> limits1 = {0,1};
  Vector<double> limits2 = {1,2};
  double y0_1 = 0, y0_2 = 1, h = 0.1;
  Vector<double> solution, analytical(10);
  int step;

  auto f1 = [](const double t, const double y)
  {
    return t*exp(3*t) - 2*y;
  };

  auto f1a = [](const double t)
  {
    return .2*t*exp(t*3) - (static_cast<double>(1)/25)*(exp(3*t) - exp(-2*t));
  };

  auto f2 = [](const double t, const double y)
  {
    double frac = y/t;
    return frac - frac*frac;
  };

  auto f2a = [](const double t)
  {
    return t/(1 + log(t));
  };


  std::ofstream fout;

  fout.open("hw8_results.txt");

  std::cout << "\n=== Part 1 ===\n";

  step = 0;
  for(int i=0; i<10; ++i)
  {
    analytical[i] = f1a(limits1[0] + h*(step));
    std::cout << h*step << ": " << analytical[i] << '\n';

    step++;
  }
  std::cout << '\n';

  solution = rk2_heun(f1, y0_1, limits1, 10);
  std::cout << solution - analytical << '\n';

  solution = rk2_modEuler(f1, y0_1, limits1, 10);
  std::cout << solution - analytical << '\n';

  solution = rk2_midEuler(f1, y0_1, limits1, 10);
  std::cout << solution - analytical << '\n';

  solution = rk4_default(f1, y0_1, limits1, 10);
  std::cout << solution - analytical << '\n';

  std::cout << "\n=== Part 2 ===\n";


  fout.close();

  return 0;
}