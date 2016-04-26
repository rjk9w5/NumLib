#include "integrators.h"

template <class T_Function>
double trapz(numlib::Vector<double> limits, int n_pts, T_Function f)
{
  double s = 0;
  double h = (limits[1] - limits[0])/(n_pts);

  for(int i=0; i<n_pts; ++i)
    s+=(f(limits[0] + i*h) + f(limits[0] + (i+1)*h));

  return s*h/2;
}

template <class T_Function>
double simpson3(numlib::Vector<double> limits, int n_pts, T_Function f)
{
  double s = f(limits[0]) + f(limits[1]);
  double I = 0, J=0;
  double h = (limits[1] - limits[0])/(n_pts);

  for(int i=1; i<n_pts; ++i)
  {
    if(i%2)
    {
      I+=f(limits[0] + i*h);
    }
    else
    {
      J+=f(limits[0] + i*h);
    }
  }

  return (h/3)*(s + 4*I + 2*J);
}


template <class T_Function>
double gaussQuad3(numlib::Vector<double> limits, T_Function f)
{
  double c1((limits[1]+limits[0])/2), c2((limits[1]-limits[0])/2);
  numlib::Vector<double> x = {-0.774597, 0, 0.774597};
  numlib::Vector<double> w = {0.555556, 0.888889, 0.555556};
  double sum=0;
  int it =0;
  for(auto& xi: x)
    sum+=w[it++]*f(xi*c2 + c1);

  return c2*sum;

}


template <class T_Function>
double gaussQuad4(numlib::Vector<double> limits, T_Function f)
{
  double c1((limits[1]+limits[0])/2), c2((limits[1]-limits[0])/2);
  numlib::Vector<double> x = {-0.861136, -0.339981, 0.339981, 0.861136};
  numlib::Vector<double> w = {0.347855, 0.652145, 0.652145, 0.347855};
  double sum=0;
  int it =0;
  for(auto& xi: x)
    sum+=w[it++]*f(xi*c2 + c1);

  return c2*sum;

}