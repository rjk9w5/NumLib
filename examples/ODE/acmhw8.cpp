/*
 *  test.cpp
 *  Author: Ryan Krattiger
 *
 *  Namespace: numlib
 *  Brief: Test integration
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "ode_examples.h"

#define PRINT_PLOT_DATA  1

using namespace numlib;

int acmhw8(int argc, char** args)
{
  if(argc) std::cout << args[0] << '\n';

  Vector<double> limits1 = {0,2};
  Vector<double> limits2 = {1,3};
  double y0_1 = 0, y0_2 = 1, h = 0.1;
  Vector<double> solution, analytical(21);
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

#ifdef PRINT_PLOT_DATA
  std::ofstream fout;

  fout.open("results.m");
#endif

  std::cout << "\n=== Part 1 ===\n";

  step = 0;
  for(int i=0; i<21; ++i)
  {
    std::cout << h*step << ' ';
    analytical[i] = f1a(limits1[0] + h*(step));
    step++;
  }
  std::cout << '\n';

  solution = rk2_heun(f1, y0_1, limits1, 20);

#ifdef PRINT_PLOT_DATA
  fout << "heun_err = [" << fabs(solution - analytical) << "];\n";
  fout << "heun_sol = [" << solution << "];\n";
#endif

  solution = rk2_modEuler(f1, y0_1, limits1, 20);
  std::cout << solution - analytical << '\n';

#ifdef PRINT_PLOT_DATA
  fout << "modeuler_err = [" << fabs(solution - analytical) << "];\n";
  fout << "modeuler_sol = [" << solution << "];\n";
#endif

  solution = rk2_midEuler(f1, y0_1, limits1, 20);
  std::cout << solution - analytical << '\n';

#ifdef PRINT_PLOT_DATA
  fout << "mideuler_err = [" << fabs(solution - analytical) << "];\n";
  fout << "mideuler_sol = [" << solution << "];\n";
#endif

  solution = rk4_default(f1, y0_1, limits1, 20);
  std::cout << solution - analytical << '\n';

#ifdef PRINT_PLOT_DATA
  fout << "rk4_err = [" << fabs(solution - analytical) << "];\n";
  fout << "rk4_sol = [" << solution << "];\n";

  fout << "p1_analytic = [" << analytical << "];\n";
#endif

  std::cout << "\n=== Part 2 ===\n";

  step = 0;
  for(int i=0; i<21; ++i)
  {
    analytical[i] = f2a(limits2[0] + h*(step));
    step++;
  }

  solution = abash_2(f2, y0_2, limits2, 20);
  std::cout << solution - analytical  << '\n';
#ifdef PRINT_PLOT_DATA
  fout << "ab2_err = [" << fabs(solution - analytical) << "];\n";
  fout << "ab2_sol = [" << solution << "];\n";
#endif

  solution = abash_4(f2, y0_2, limits2, 20);
  std::cout << solution - analytical  << '\n';
#ifdef PRINT_PLOT_DATA
  fout << "ab4_err = [" << fabs(solution - analytical) << "];\n";
  fout << "ab4_sol = [" << solution << "];\n";
#endif

  solution = abash_5(f2, y0_2, limits2, 20);
  std::cout << solution - analytical  << '\n';
#ifdef PRINT_PLOT_DATA
  fout << "ab5_err = [" << fabs(solution - analytical) << "];\n";
  fout << "ab5_sol = [" << solution << "];\n";
#endif

  solution = abash_3(f2, y0_2, limits2, 20);
  std::cout << solution - analytical  << '\n';
#ifdef PRINT_PLOT_DATA
  fout << "ab3_err = [" << fabs(solution - analytical) << "];\n";
  fout << "ab3_sol = [" << solution << "];\n";

  fout << "p2_analytic = [" << analytical << "];\n";

  fout.close();
#endif

  return 0;
}