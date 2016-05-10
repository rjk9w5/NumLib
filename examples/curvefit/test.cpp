/*
 * test.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: ryan
 */

#define DEBUGFULL

#include "../../include/common/exceptions.h"
#include "../../include/linearsystems/linearsystem_solvers.h"
#include "../../include/common/coord.h"
#include "../../include/common/istream_utility.h"
#include "../../include/curvefit/cspline.h"
#include <iostream>
#include <fstream>

int main(int nargs, char** args)
{
  try
  {
    std::size_t pts;
    double dummy;

    numlib::Vector<numlib::Coordinate<double>> inp;
    numlib::CSpline<double> CSpN, CSpC;

    auto actaul_f = [](double const x)
    {
      return x*x*x*sin(2*x) - 2*x;
    };

    std::ifstream fin;
    if(nargs > 1) fin.open(args[1]);

    if(!fin.is_open())
      fin.open("exam_input");

    std::cout << "Reading Input file:\n";
    fin >> pts;
    std::cout << pts << '\n';
    inp.set_size(pts);
    for(std::size_t i=0; i<pts; ++i)
    {
      // if(!numlib::checkIstream(fin)) break;
      fin >> dummy;
      inp[i].x(dummy);
      // if(!numlib::checkIstream(fin)) break;
      fin >> dummy;
      inp[i].y(dummy);
    }
    fin.close();
    std::cout << inp << '\n';

    CSpC.points_clamped(inp, -46.3049770277488, 42.3049770277488);
    CSpN.points(inp);

    // std::cout << "=== Evaluate @ x = -2.0 ===\n";
    // std::cout << "Cubic Spline:   " << CSp(-2.0) << '\n';
    // std::cout << "Actual:         " << actaul_f(-2.0) << '\n' << '\n';
    //
    // std::cout << "=== Evaluate @ x = -0.9 ===\n";
    // std::cout << "Cubic Spline:   " << CSp(-0.9) << '\n';
    // std::cout << "Actual:         " << actaul_f(-0.9) << '\n' << '\n';
    //
    // std::cout << "=== Evaluate @ x = -0.7 ===\n";
    // std::cout << "Cubic Spline:   " << CSp(-0.7) << '\n';
    // std::cout << "Actual:         " << actaul_f(-0.7) << '\n' << '\n';
    //
    // std::cout << "=== Evaluate @ x = 0.1 ===\n";
    // std::cout << "Cubic Spline:   " << CSp(0.1) << '\n';
    // std::cout << "Actual:         " << actaul_f(0.1) << '\n' << '\n';

    CSpN.write_octave("csplineN_exam2");
    CSpC.write_octave("csplineC_exam2");

  }
  catch(numlib::Exception &except)
  {
    std::cerr << except.errMsg() << '\n';
  }
  return 0;
}
