#include "../../include/rootfinding/sloping.h"

int main(int argc, char** args)
{

  double root;
  auto f1 = [](const double x)
  {
    return x*x*x + x*x - 2;
  };

  root = secant(f1,0.0,0.1);

  std::cout << "Root at x = " << root << " and y = " << f1(root) << '\n';
  
  return 0;
}