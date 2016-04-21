/*
 * vector.hpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief: Declarations of vector template class and associated
 *              friend functions
 */

template <class T>
numlib::Vector<T>::Vector(): size_(0)
{
  allocate();
}

template <class T>
numlib::Vector<T>::Vector(const size_t size):
    size_(size)
{
  allocate();
}

template <class T>
numlib::Vector<T>::Vector(const size_t size, const T& value):
    size_(size)
{
  allocate();
  for(size_t i=0; i < size_; ++i)
  {
    data_[i] = value;
  }
}

template <class T>
numlib::Vector<T>& numlib::Vector<T>::operator =(numlib::Vector<T> src)
{
  swap(*this, src);

  return *this;
}

template <class T>
numlib::Vector<T>::Vector(const numlib::Vector<T>& src): size_(src.size_)
{
  allocate();
  for(std::size_t i=0; i<size_; ++i)
  {
    data_[i] = src.data_[i];
  }
}

template <class T>
numlib::Vector<T>::Vector(numlib::Vector<T> &&other):
    numlib::Vector<T>()
{
  swap(*this, other);
}

template <class T>
numlib::Vector<T>::Vector(
  std::initializer_list<T> const &l):
  size_(l.size())
{
  allocate();
  std::size_t i=0;
  for(auto li: l)
  {
    data_[i++] = li;
  }
}

template <class T>
numlib::Vector<T>::~Vector()
{
  deallocate();
}

template <class T>
void numlib::Vector<T>::resize(const size_t size)
{
  T* tmp = nullptr;
  size_t nit = (size > size_?size_:size);
  if(size < 0) numlib::FatalError("numlib::Vector<T>::resize(const size_t size):" \
                              " Input size must be greater than or equal to"\
                              " zero!\n");

  if(data_ != nullptr && size_ && size)
  {
    tmp = new T[size_];
    for(size_t i=0; i < size_; ++i)
    {
      tmp[i] = data_[i];
    }
  }
  clear();
  data_ = new T[size];

  if(tmp != nullptr)
  {
    for(size_t i=0; i < nit; ++i)
    {
      data_[i] = tmp[i];
    }
  }
  size_ = size;

  return;
}

template <class T>
void numlib::Vector<T>::reuse(const size_t size)
{
  deallocate();
  if(size > 0)
    data_ = new T[size];
  else
    data_ = nullptr;

  size_ = size;

  return;
}

template <class T>
void numlib::Vector<T>::clear()
{
  deallocate();

  return;
}

template <class T>
void numlib::Vector<T>::set_size(const size_t size)
{
  this->reuse(size);
  return;
}

template <class T>
void numlib::Vector<T>::remove(const size_t i)
{
  if(!(i < size_ && i >=0))
    throw numlib::FatalError("numlib::Vector<T>::remove(const size_t i): "\
                         "Index 'i' is out of range\n");

  for(size_t j = i; j < size_ - 1; ++j)
    data_[j] = data_[j+1];

  size_--;

  return;
}

template <class T>
const T& numlib::Vector<T>::operator[](const size_t i) const
{
  if(i > size_ || i < 0)
  {
    throw numlib::FatalError("numlib::Vector<T>::operator[](const size_t i) const: "\
                         "Index 'i' is out of range\n");
  }

  return data_[i];
}

template <class T>
T& numlib::Vector<T>::operator[](const size_t i)
{
  if(i > size_ || i < 0)
  {
    throw numlib::FatalError("numlib::Vector<T>::operator[](const size_t i): "\
                         "Index 'i' is out of range\n");
  }

  return data_[i];
}

// Must have < operator implemented
template <class T>
numlib::Vector<T>& numlib::Vector<T>::sort()
{
  if(!std::is_sorted(begin(), end()))
    std::sort(begin(), end());

  return *this;
}

template <class T>
T* numlib::Vector<T>::begin() const
{
  return data_;
}

template <class T>
T* numlib::Vector<T>::end() const
{
  return data_+ size_;
}

template <class T>
int numlib::Vector<T>::find(const T& value)
{
  size_t i_left=0;
  size_t i_right = size_-1;
  size_t index = (i_right - i_left)/2;

  if(data_[i_right] == value) return i_right;
  if(data_[i_left] == value) return i_left;

  while(data_[index] != value)
  {
    if(data_[index] > value)
    {
      i_right = index;
      index = i_left + (i_right - i_left)/2;
    }
    else if(data_[index] < value)
    {
          i_left = index;
          index = i_left + (i_right - i_left)/2;
    }

    if(i_left == index) return -1;
  }

  return index;
}

template <class Ele_T>
void numlib::Vector<Ele_T>::ele_swap(std::size_t const i1, std::size_t const i2)
{
  if(!checki(i1))
    throw numlib::FatalError(
        "In numlib::Vector<Ele_T>::ele_swap: Argument 1 is out of bounds!");

  if(!checki(i2))
    throw numlib::FatalError(
        "In numlib::Vector<Ele_T>::ele_swap: Argument 1 is out of bounds!");

  Ele_T tmp(data_[i1]);
  data_[i1] = data_[i2];
  data_[i2] = tmp;

  return;
}

// MATH
template <class T>
T numlib::Vector<T>::dot(const numlib::Vector<T>& vec) const
{
  if(vec.get_size() != get_size())
    throw numlib::FatalError("numlib::Vector<T>::dot(const numlib::Vector<T>& vec): "\
                         "Vectors must be of same size!\n");

  T ret=0;
  size_t it = 0;
  for(auto& val: *this)
    ret += val*vec[it++];

  return ret;
}

template <class T>
T numlib::dot(const numlib::Vector<T>& v1, const numlib::Vector<T>& v2)
{
  return v1.dot(v2);
}

template <class T>
T numlib::Vector<T>::operator * (const numlib::Vector<T>& vec) const
{
  return dot(vec);
}

template <class T>
numlib::Vector<T> numlib::Vector<T>::operator * (const T& C) const
{
  numlib::Vector<T> ret(*this);
  size_t it=-1;
  for(auto& val: *this)
    ret[++it] = val*C;

  return  ret;
}

template <class T>
numlib::Vector<T> numlib::Vector<T>::operator / (const numlib::Vector<T>& v2) const
{
  if(v2.get_size() != get_size())
    throw numlib::FatalError("numlib::Vector<T>::operator / " \
                         "(const numlib::Vector<T>& v2): "\
                         "Vectors must be of same size!\n");

  numlib::Vector<T> ret(*this);
  size_t it =0;
  for(auto& val: v2)
  {
    ret[it++] /= val;
  }
  return ret;
}

template <class T>
numlib::Vector<T> numlib::Vector<T>::operator / (const T& C) const
{
  numlib::Vector<T> ret(*this);
  size_t it =0;
  for(auto& val: ret)
  {
    ret[it++] /= C;
  }
  return ret;
}

template <class T>
numlib::Vector<T>& numlib::Vector<T>::operator += (const numlib::Vector<T>& vec)
{
  if(vec.get_size() != get_size())
    throw numlib::FatalError("numlib::Vector<T>::operator += " \
                             "(const numlib::Vector<T>& vec): "\
                             "Vectors must be of same size!\n");

  size_t it=0;
  for(auto& val: vec)
    this -> operator[](it++) += val;

  return *this;
}

template <class T>
numlib::Vector<T>& numlib::Vector<T>::operator -= (const numlib::Vector<T>& vec)
{
  if(get_size() != vec.get_size())
    throw numlib::FatalError("numlib::operator - (const numlib::Vector<T>& v1," \
                         "const numlib::Vector<T>& v2): "                 \
                         "Vectors must be of same size!\n");
  size_t it=-1;
  for(auto& val: vec)
    this -> operator[](++it) -= val;

  return *this;
}

template <class Ele_T>
void numlib::Vector<Ele_T>::allocate()
{
  data_ = (size_?new Ele_T[size_]:nullptr);
  return;
}

template <class Ele_T>
void numlib::Vector<Ele_T>::deallocate()
{
  delete[] data_;
  size_=0;

  return;
}

template <class T>
T numlib::Vector<T>::sum() const
{
  T sm=0;
  for(auto& val: *this)
  {
    sm += val;
  }
  return sm;
}
