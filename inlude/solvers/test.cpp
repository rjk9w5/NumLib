#include "qr_orthonormal.h"
#include "../matrices/matrices.h"
#include "../common/istream_utility.h"
#include "../common/exceptions.h"
#include  <string>

using namespace numlib;

Dense<double> read_input(std::ifstream &fin);

int main(int argc, char* argv[])
{
  try
  {
    std::ifstream fin;

    Dense<double> dmat, Q;
    UpperTriangle<double> R;
    QR_OrthoNormal<double> qr;

    for(int i=0; i<argc; ++i)
    {
      std::cout << argv[i] << ' ';
    }
    std::cout << '\n';

    if(argc>1)
      fin.open(argv[1]);
    else
      fin.open("test2");

    if(!fin.is_open())
      throw numlib::FatalError("Bad File!");

    dmat = read_input(fin);

    std::cout << dmat << '\n';
    int loop = 10000;
    while(loop--)
    {
      qr(dmat,Q,R);
      std::cout << Q << '\n';
      std::cout << R << '\n';
      dmat = R*Q;
      std::cout << dmat << '\n';
    }
  }
  catch(numlib::Exception& e)
  {
    std::cerr << e.errMsg() << '\n';
  }
  return 0;
}

Dense<double> read_input(std::ifstream& fin)
{
  std::size_t n;
  fin >> n;

  std::cout << n << '\n';

  Dense<double> var(n);
  if(n)
  {
    for(std::size_t i=0; i<n; ++i)
    {
      for(std::size_t j=0; j<n; ++j)
      {
        if(checkIstream(fin))
          fin >> var[{i,j}];
      }
    }
  }
  std::cout << var << '\n';
  return var;
}
