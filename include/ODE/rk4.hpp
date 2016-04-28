template <class T, class TFunc>
numlib::Vector<typename float_trait<T>::T_float> 
rk4_default(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename float_trait<T>::T_float> result(n);
  typename float_trait<T>::T_float h = static_cast<typename float_trait<T>::T_float>((limits[1] - limits[0]))/n;

  typename float_trait<T>::T_float k1, k2, k3, k4;

  for(int i=0; i<n-1; ++i)
  {
    k1 = h*f(limits[0] + i*h, result[i]);
    k2 = h*f(limits[0] + (i+0.5)*h, result[i] + 0.5*k1);
    k3 = h*f(limits[0] + (i+0.5)*h, result[i] + 0.5*k2);
    k4 = h*f(limits[0] + (i+1)*h, result[i] + k3);

    result[i+1] = result[i] + static_cast<typename float_trait<T>::T_float>(1)/6*(k1 + 2*k2 + 2*k3 + k4);
  }

  return result;
}