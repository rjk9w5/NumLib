template <class T, class TFunc>
numlib::Vector<typename float_trait<T>::T_float> 
rk2_heun(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename float_trait<T>::T_float> result(n+1);
  typename float_trait<T>::T_float h = static_cast<typename float_trait<T>::T_float>((limits[1] - limits[0]))/n;

  typename float_trait<T>::T_float c = static_cast<typename float_trait<T>::T_float>(2)/3, k1, k2;

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
numlib::Vector<typename float_trait<T>::T_float> 
rk2_modEuler(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename float_trait<T>::T_float> result(n+1);
  typename float_trait<T>::T_float h = static_cast<typename float_trait<T>::T_float>((limits[1] - limits[0]))/n;

  typename float_trait<T>::T_float c = 1, k1, k2;

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
numlib::Vector<typename float_trait<T>::T_float> 
rk2_midEuler(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename float_trait<T>::T_float> result(n+1);
  typename float_trait<T>::T_float h = static_cast<typename float_trait<T>::T_float>((limits[1] - limits[0]))/n;

  typename float_trait<T>::T_float c = 0.5, k1, k2;

  result[0] = initv;

  for(int i=0; i<n; ++i)
  {
    k1 = f(limits[0] + i*h, result[i]);
    k2 = f(limits[0] + (i+c)*h, result[i] + c*h*k1);
    result[i+1] = result[i] + h*(k2);
  }

  return result;
}