#include "qr_orthonormal.h"
#include "../matrices/matrices.h"
#include "../common/istream_utility.h"

using namespace numlib;

void read_input(char* fname);

int main(int narg; char** args)
{
  Dense<Type> dmat;
  if(narg>1) read_input(args[1], dmat);
}

void read_input(char* fname)
{
  std::ifstream fin;
  fin.open(fname);

  std::size_t n,m;
  if(fin.isopen() && checkIstream(fin))
    fin >> n;

  if(n_>0 && m_>0)
  {
    for(std::size_t i=0; i<n_; ++i)
    {
      for(std::size_t j=0; j<m_; ++j)
      {
        if(checkIstream(fin))
          fin >> var[{i,j}];
      }
    }
  }
  return;
}
