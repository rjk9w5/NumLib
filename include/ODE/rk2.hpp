template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
rk2_heun(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename promote_float<T>::type> result(n+1);
  typename promote_float<T>::type h = static_cast<typename promote_float<T>::type>((limits[1] - limits[0]))/n;

  typename promote_float<T>::type c = static_cast<typename promote_float<T>::type>(2)/3, k1, k2;

  result[0] = initv;

  for(int i=0; i<n; ++i)
  {
    k1 = f(limits[0] + i*h, result[i]);
    k2 = f(limits[0] + (i+c)*h, result[i] + c*h*k1);
    result[i+1] = result[i] + 0.25*h*(k1 + 3*k2);
  }

  return result;
}

template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
rk2_modEuler(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename promote_float<T>::type> result(n+1);
  typename promote_float<T>::type h = static_cast<typename promote_float<T>::type>((limits[1] - limits[0]))/n;

  typename promote_float<T>::type c = 1, k1, k2;

  result[0] = initv;

  for(int i=0; i<n; ++i)
  {
    k1 = f(limits[0] + i*h, result[i]);
    k2 = f(limits[0] + (i+c)*h, result[i] + c*h*k1);
    result[i+1] = result[i] + 0.5*h*(k1 + k2);
  }

  return result;
}

template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
rk2_midEuler(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename promote_float<T>::type> result(n+1);
  typename promote_float<T>::type h = static_cast<typename promote_float<T>::type>((limits[1] - limits[0]))/n;

  typename promote_float<T>::type c = 0.5, k1, k2;

  result[0] = initv;

  for(int i=0; i<n; ++i)
  {
    k1 = f(limits[0] + i*h, result[i]);
    k2 = f(limits[0] + (i+c)*h, result[i] + c*h*k1);
    result[i+1] = result[i] + h*(k2);
  }

  return result;
}
