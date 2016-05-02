template <class T, class TFunc>
typename promote_float<T>::type
secant(TFunc f, T x0, T x1)
{
  typename promote_float<T>::type x_new;
  numlib::converge::tolerance<T> tol;
  typename promote_float<T>::type err = 1;
  int max_it = 100, it=0;

  while(err > tol.HYPER_FINE && it++ < max_it)
  {
    x_new = x1 - (f(x1)*(x1-x0))/(f(x1)-f(x0));
    x0 = x1;
    x1 = x_new;
    err = fabs(x1-x0)/fabs(x1);
  }

  if(it >= max_it)
  {
    std::cerr << "Warning: Secant exited at max iterations of " << max_it << '\n';
  }

  return x_new;
}

// template <class T, class TFunc>
// typename promote_float<T>::type
// modsecant(TFunc f, T x0, T x1, T x2)
// {
//   typename promote_float<T>::type x_new;
//   numlib::converge::tolerance<T> tol;
//   typename promote_float<T>::type err = 1;
//   int max_it = 100, it=0;
//
//   while(err > tol.NORMAL && it++ < max_it)
//   {
//     x_new = x1 - (f(x1)*(x1-x0))/(f(x1)-f(x0));
//     x0 = x1;
//     x1 = x_new;
//     err = fabs(x1-x0)/fabs(x1);
//
//     std::cout << "x_new: " << x_new << " err: " << err << '\n';
//   }
//   return x_new;
// }
