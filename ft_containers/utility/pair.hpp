#ifndef PAIR_H
# define PAIR_H

namespace ft {


/**
 * Template class that provides a way to store
 * two heterogeneous objects as a single unit
**/
template<class T1, class T2>
struct pair {

  typedef T1  first_type;
  typedef T2  second_type;

  first_type  first;
  second_type second;

  pair(void) : first(), second() {}

  template<class U1, class U2>
  pair(const pair<U1, U2>& pr) : first(pr.first), second(pr.second) {}

  pair(const first_type& a, const second_type& b) : first(a), second(b) {}

  pair& operator=(const pair& pr) {
    if (this != &pr) {
      this->first = pr.first;
      this->second = pr.second;
    }
    return *this;
  }

};


/**
 * Relational operators overloading for ft::pair
**/
template<class T1, class T2>
inline bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

template<class T1, class T2>
inline bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(lhs == rhs); }

template<class T1, class T2>
inline bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template<class T1, class T2>
inline bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(rhs < lhs); }

template<class T1, class T2>
inline bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return rhs < lhs; }

template<class T1, class T2>
inline bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(lhs < rhs); }


/**
 * Creates ft::pair object, deducing the
 * target type from the types of arguments
**/
template<class T1, class T2>
ft::pair<T1, T2> make_pair(T1 a, T2 b) { return ft::pair<T1, T2>(a, b); }


}

#endif // PAIR_H
