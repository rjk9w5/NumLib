template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
rk4_default(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename promote_float<T>::type> result(n+1);
  typename promote_float<T>::type h = static_cast<typename promote_float<T>::type>((limits[1] - limits[0]))/n;

  typename promote_float<T>::type k1, k2, k3, k4;

  result[0] = initv;

  for(int i=0; i<n; ++i)
  {
    k1 = h*f(limits[0] + i*h, result[i]);
    k2 = h*f(limits[0] + (i+0.5)*h, result[i] + 0.5*k1);
    k3 = h*f(limits[0] + (i+0.5)*h, result[i] + 0.5*k2);
    k4 = h*f(limits[0] + (i+1)*h, result[i] + k3);

    result[i+1] = result[i] + static_cast<typename promote_float<T>::type>(1)/6
                              *(k1 + 2*k2 + 2*k3 + k4);
  }

  return result;
}
