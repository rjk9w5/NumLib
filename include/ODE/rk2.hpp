template <class T_initv, class T_lims, class TFunc>
numlib::Vector<typename promote_float<T_initv>::type>
rk2_heun(const TFunc f, 
            T_initv const &initv, 
            numlib::Vector<T_lims> limits, 
            std::size_t const n)
{
  numlib::Vector<typename promote_float<T_initv>::type> result(n+1);
  typename promote_float<T_lims>::type h = static_cast<typename promote_float<T_lims>::type>((limits[1] - limits[0]))/n;

  typename promote_float<T_lims>::type c = static_cast<typename promote_float<T_lims>::type>(2)/3;
  typename promote_float<T_initv>::type k1, k2;

  result[0] = initv;

  for(int i=0; i<n; ++i)
  {
    k1 = f(limits[0] + i*h, result[i]);
    k2 = f(limits[0] + (i+c)*h, result[i] + c*h*k1);
    result[i+1] = result[i] + 0.25*h*(k1 + 3.0*k2);
  }

  return result;
}

template <class T_initv, class T_lims, class TFunc>
numlib::Vector<typename promote_float<T_initv>::type>
rk2_modEuler(const TFunc f, 
            T_initv const &initv, 
            numlib::Vector<T_lims> limits, 
            std::size_t const n)
{
  numlib::Vector<typename promote_float<T_initv>::type> result(n+1);
  typename promote_float<T_lims>::type h = static_cast<typename promote_float<T_lims>::type>((limits[1] - limits[0]))/n;

  typename promote_float<T_lims>::type c = 1;
  typename promote_float<T_initv>::type k1, k2;

  result[0] = initv;

  for(int i=0; i<n; ++i)
  {
    k1 = f(limits[0] + i*h, result[i]);
    k2 = f(limits[0] + (i+c)*h, result[i] + c*h*k1);
    result[i+1] = result[i] + 0.5*h*(k1 + k2);
  }

  return result;
}

template <class T_initv, class T_lims, class TFunc>
numlib::Vector<typename promote_float<T_initv>::type>
rk2_midEuler(const TFunc f, 
            T_initv const &initv, 
            numlib::Vector<T_lims> limits, 
            std::size_t const n)
{
  numlib::Vector<typename promote_float<T_initv>::type> result(n+1);
  typename promote_float<T_lims>::type h = static_cast<typename promote_float<T_lims>::type>((limits[1] - limits[0]))/n;

  typename promote_float<T_lims>::type c = 0.5;
  typename promote_float<T_initv>::type k1, k2;

  result[0] = initv;

  for(int i=0; i<n; ++i)
  {
    k1 = f(limits[0] + i*h, result[i]);
    k2 = f(limits[0] + (i+c)*h, result[i] + c*h*k1);
    result[i+1] = result[i] + h*(k2);
  }

  return result;
}
