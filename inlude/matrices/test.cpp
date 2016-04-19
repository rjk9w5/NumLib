#include "dense.h"
#include <iostream>

using namespace numlib;


int main(int narg, char** args)
{
  try
  {
    Dense<double> dmat2(4,5);
    // Matrix<double,Dense>* dmat2 = new Dense<double>(4,5);

    for(std::size_t i=0; i<4; ++i)
    {
      for(std::size_t j=0; j<5; ++j)
      {
        // dmat2->operator[]({i,j}) = i*j + 1;
        dmat2[{i,j}] = i*j+1;
      }
    }

    std::cout << "Assigned Matrix values\n";

    // dmat = *dmat2;
    // dmat2 += dmat2;
    // dmat2->operator+=(*dmat2);
    // dmat = *dmat2 - dmat;
    dmat2 = dmat2 - dmat2;
    // dmat=(*dmat2 + *dmat2);
    // std::cout << dmat2 + dmat2 << '\n';

    std::cout << dmat2 << '\n';

    // std::cout << dmat << '\n';

    if(narg>1) std::cout << args[1] << '\n';
    // delete dmat2;
  }
  catch(Exception& e)
  {
    std::cerr << e.errMsg() << '\n';
  }
  return 0;
}
