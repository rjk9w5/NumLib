#include "blasius.h"
#include <fstream>

int main()
{
  numlib::Vector<numlib::Vector<double>> solution;
  std::ofstream fout;
  numlib::converge::tolerance<double> tol;
  double upper = 1, s_old=0, diff = 1;;

  fout.open("results.m");

  while(diff > tol.HYPER_FINE)
  {
    solution = blasius(upper, upper*10);
    diff = fabs(solution[0][2] - s_old);
    s_old = solution[0][2];

    if(upper == 1 || upper == 2 || upper == 5 || upper == 7 || upper == 10)
      fout << "blas_" << static_cast<int>(upper) << " = [" << solution << "];\n\n";

    upper++;
  }
  
  fout << "converge_at = " << upper - 1 << ";\n";
  fout << "blas_converged = [" << solution << "];\n\n";
  
  fout.close();

  return 0;
}