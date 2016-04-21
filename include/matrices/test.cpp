#include "dense.h"
#include "diagonal.h"
#include "../vector/vector.h"
#include <iostream>

using namespace numlib;
#define USE_EXCEPTIONS 1

int main(int narg, char** args)
{
  #if USE_EXCEPTIONS
  try
  {
  #endif
    std::size_t r(4),c(6);
    Vector<double> v({1,0,0,1,2,3});
    Dense<double> tm0(r,c);
    Diag<double> diagtwos = eye<double>(r);
    std::shared_ptr<Matrix<double,Dense>> dmat2;

    for(std::size_t i=0; i<r; ++i)
    {
      diagtwos[{i,i}]*=i;
      for(std::size_t j=0; j<c; ++j)
      {
        tm0.checkj(j);
        tm0.checki(i);
        tm0[{i,j}] = i*j+1;
      }
    }

    dmat2 = tm0.clone();
    std::cout << tm0 << '\n';

    std::cout << "Assigned Matrix values\n";
    std::cout << diagtwos + tm0 << '\n';
    tm0 = diagtwos*tm0;
    std::cout << tm0 - *dmat2 << '\n';
    v = eye<double>(c)*v;
    std::cout << v << '\n';

    if(narg>1) std::cout << args[1] << '\n';
  #if USE_EXCEPTIONS
  }
  catch(Exception& e)
  {
    std::cerr << e.errMsg() << '\n';
  }
  #endif
  return 0;
}
