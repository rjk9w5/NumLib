template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
abash_2(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename promote_float<T>::type> result(n+1), tmp;
  typename promote_float<T>::type h = static_cast<typename promote_float<T>::type>((limits[1] - limits[0]))/n;

  tmp = rk4_default(f, initv, {limits[0], limits[0]+2*h}, 2);
  result[0] = tmp[0];
  result[1] = tmp[1];

  for(int i=1; i<n; ++i)
  {
    result[i+1] = result[i] +
    h*0.5*(
         3*f(limits[0] + i*h, result[i])
         - f(limits[0] + (i-1)*h, result[i-1]));
  }

  return result;
}

template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
abash_3(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename promote_float<T>::type> result(n+1), tmp;
  typename promote_float<T>::type
      h = static_cast<typename promote_float<T>::type>((limits[1] - limits[0]))/n,
      c = static_cast<typename promote_float<T>::type>(1)/12;

  tmp = rk4_default(f, initv, {limits[0], limits[0]+3*h}, 3);
  result[0] = tmp[0];
  result[1] = tmp[1];
  result[2] = tmp[2];

  for(int i=2; i<n; ++i)
  {
    result[i+1] = result[i] +
    h*c*(
         23*f(limits[0] + i*h, result[i])
         - 16*f(limits[0] + (i-1)*h, result[i-1])
         + 5*f(limits[0] + (i-2)*h, result[i-2]));
  }

  return result;
}

template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
abash_4(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename promote_float<T>::type> result(n+1), tmp;
  typename promote_float<T>::type
      h = static_cast<typename promote_float<T>::type>((limits[1] - limits[0]))/n,
      c = static_cast<typename promote_float<T>::type>(1)/24;

  tmp = rk4_default(f, initv, {limits[0], limits[0]+4*h}, 4);
  result[0] = tmp[0];
  result[1] = tmp[1];
  result[2] = tmp[2];
  result[3] = tmp[3];

  for(int i=3; i<n; ++i)
  {
    result[i+1] = result[i] +
    h*c*(
         55*f(limits[0] + i*h, result[i])
         - 59*f(limits[0] + (i-1)*h, result[i-1])
         + 37*f(limits[0] + (i-2)*h, result[i-2])
         - 9*f(limits[0] + (i-3)*h, result[i-3]));
  }

  return result;
}

template <class T, class TFunc>
numlib::Vector<typename promote_float<T>::type>
abash_5(const TFunc f,T const &initv, numlib::Vector<T> limits, std::size_t const n)
{
  numlib::Vector<typename promote_float<T>::type> result(n+1), tmp;
  typename promote_float<T>::type
      h = static_cast<typename promote_float<T>::type>((limits[1] - limits[0]))/n,
      c = static_cast<typename promote_float<T>::type>(1)/720;

  tmp = rk4_default(f, initv, {limits[0], limits[0]+5*h}, 5);
  result[0] = tmp[0];
  result[1] = tmp[1];
  result[2] = tmp[2];
  result[3] = tmp[3];
  result[4] = tmp[4];

  for(int i=4; i<n; ++i)
  {
    result[i+1] = result[i] +
    h*c*(
         1901*f(limits[0] + i*h, result[i])
         - 2774*f(limits[0] + (i-1)*h, result[i-1])
         + 2616*f(limits[0] + (i-2)*h, result[i-2])
         - 1274*f(limits[0] + (i-3)*h, result[i-3])
         + 251*f(limits[0] + (i-4)*h, result[i-4]));
  }

  return result;
}
