#include "include/solvers/qr_orthonormal.h"
#include "include/matrices/matrices.h"
#include "include/common/istream_utility.h"
#include "include/common/exceptions.h"

using namespace numlib;

Dense<double> read_input(std::ifstream &fin);
double diag_prod(Dense<double> Q);

int oonm_hw6_main(int argc, char** argv)
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
      fin.open("test1");

    std::cout << dmat << '\n';

    if(!fin.is_open())
      throw numlib::FatalError("Bad File!");

    dmat = read_input(fin);

    int loop = 100;
    int final_it;
    while(loop--)
    {
      qr(dmat,Q,R);
      // std::cout << Q << '\n';
      // std::cout << R << '\n';
      dmat = R*Q;
      // std::cout << dmat << '\n';
      if(!((100-loop)%5) && (100-loop)<=10)
      {
        std::cout << "Iteration #" << 100-loop << '\n';
        std::cout << dmat << '\n';
      }
      if(diag_prod(Q)==1)
      {
        final_it=100-loop;
        loop=0;
      }
    }

    std::cout << "Total No. of iterations: " << final_it << '\n';
    std::cout << dmat << '\n';
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

  return var;
}

double diag_prod(Dense<double> Q)
{
  std::size_t n = Q.N();
  double prod = 1;
  for(std::size_t i=0;i<n;++i)
  {
    prod*=Q[{i,i}];
  }
  return prod;
}