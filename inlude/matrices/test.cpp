#include "matrix.h"
#include "dense.h"
#include <iostream>

using namespace numlib;


int main(int narg, char** args)
{
  Dense<double> dmat;
  Matrix<double>* dmat2 = new Dense<double>(4,5);
  std::shared_ptr<MatrixCRTP<double,Dense>> cldmat2;

  for(std::size_t i=0; i<4; ++i)
  {
    for(std::size_t j=0; j<5; ++j)
    {
      dmat2->operator[]({i,j}) = i*j + 1;
      // dmat2[{i,j}] = i*j+1;
    }
  }
  cldmat2 = dmat2->clone();
  dmat = *static_cast<Dense<double>*>(dmat2);
  // dmat2 += dmat2;
  dmat2->operator+=(*dmat2);
  cldmat2->operator+(dmat);
  // dmat=(*dmat2 + *dmat2);

  // std::cout << dmat2 + dmat2 << '\n';

  std::cout << *dmat2 << '\n';

  std::cout << *cldmat2 << '\n';

  if(narg>1) std::cout << args[1] << '\n';
  delete dmat2;
  return 0;
}
