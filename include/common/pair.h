/* ************************************************************************** *\
 * pair.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Ryan Krattiger (rjk9w5)
 *       Brief:
\* ************************************************************************** */

/*
 *   class: Pair
 *   brief: A templated class that defines a pair as a Key and Value
 */

/*
 *    Function: Pair()
 *       Brief: Default constructor
 *         Pre: None
 *        Post: Constructs a pair
 */

/*
 *    Function: Pair(Key_T, Value_T)
 *       Brief: Cosntructor with inputs for Key and Value
 *         Pre:
 *        Post: Constructs a pair
 */

/*
 *    Function: operator <, >, ==, !=, <=, >= (Pair) const
 *       Brief: Comparison operators between Pairs
 *       Input: Pair type to compare against
 *         Pre: Key_T must be overloaded for use of < operator
 *        post: returns bool result of comparing keys of each pair
 *      return: bool result of comparing keys of each pair
 */

/*
 *    Function: operator <, >, ==, !=, <=, >= (Key_T) const
 *       Brief: Comparison operators of Pair [comparison] Key_T
 *       Input: Key_T type to compare against
 *         Pre: Key_T must be overloaded for use of < operator
 *        post: returns bool result of comparing key of pair and input Key_T
 *      return: bool result of comparing keys of pair and input Key_T
 */

/*
 *   Function: operator Key_T
 *      Brief: Conversion of Pair to Key_T
 *        pre: None
 *       post: returns as key of Pair object
 *     return: key of Pair object
 */

/*
 *   Function: operator Value_T
 *      Brief: Conversion of Pair to Value_T
 *        pre: None
 *       post: returns as value of Pair object
 *     return: value of Pair object
 */

#ifndef PAIR_H_
#define PAIR_H_


namespace numlib
{

  template <class Key_T, class Value_T>
  class Pair;

  template <class Key_T, class Value_T>
  struct Pair
  {
      Pair(): key_(), value_() {}
      Pair(Key_T const &k, Value_T const &v);

      bool
      operator < (
          Key_T const &ref_key) const
      {
        return key_ < ref_key;
      }

      bool
      operator == (
          Key_T const &ref_key) const
      {
        return !(key_ < ref_key || ref_key < key_);
      }

      bool
      operator != (
          Key_T const &ref_key) const
      {
        return !(*this == ref_key);
      }

      bool
      operator <= (
          Key_T const &ref_key) const
      {
        return key_ < ref_key || *this == ref_key;
      }

      bool
      operator > (
          Key_T const &ref_key) const
      {
        return !(*this <= ref_key);
      }

      bool
      operator >= (
          Key_T const &ref_key) const
      {
        return !(*this < ref_key);
      }
// ------------------------------------------
      bool
      operator < (
          Pair const &ref_p) const
      {
        return ref_p > key_;
      }

      bool
      operator == (
          Pair const &ref_p) const
      {
        return !(key_ < ref_p || ref_p < key_);
      }

      bool
      operator != (
          Pair const &ref_p) const
      {
        return !(*this == ref_p);
      }

      bool
      operator <= (
          Pair const &ref_p) const
      {
        return key_ < ref_p || *this == ref_p;
      }

      bool
      operator > (
          Pair const &ref_p) const
      {
        return !(*this <= ref_p);
      }

      bool
      operator >= (
          Pair const &ref_p) const
      {
        return !(*this < ref_p);
      }

      operator Key_T()
      {
        return key_;
      };

      operator Value_T()
      {
        return value_;
      };

      Key_T key_;
      Value_T value_;
  };

  template <class Key_T, class Value_T>
  bool
  operator < (
      Key_T const &ref_key,
      Pair<Key_T, Value_T> const &p)
  {
    return p < ref_key;
  }

  template <class Key_T, class Value_T>
  bool
  operator > (
      Key_T const &ref_key,
      Pair<Key_T, Value_T> const &p)
  {
    return p > ref_key;
  }

}


#endif /* PAIR_H_ */
