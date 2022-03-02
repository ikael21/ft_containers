#ifndef UTILITY_H
# define UTILITY_H

namespace ft {


/* ******************************************* */
/* class template that provides a way to store */
/* two heterogeneous objects as a single unit. */
/* ******************************************* */
template<class T1, class T2>
struct pair {

	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type	second;

	pair(void)
	: first(), second() {}

	template<class U1, class U2>
	pair(const pair<U1, U2>& pr)
	: first(pr.first), second(pr.second) {}

	pair(const first_type& a, const second_type& b)
	: first(a), second(b) {}

	pair&	operator=(const pair& pr) {
		if (this != &pr) {
			this->first = pr.first;
			this->second = pr.second;
		}
		return *this;
	}

};


/* ********************************************* */
/* relational operators overloading for ft::pair */
/* ********************************************* */
template<class T1, class T2>
bool	operator==(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

template<class T1, class T2>
bool	operator!=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
{ return !(lhs == rhs); }

template<class T1, class T2>
bool	operator<(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template<class T1, class T2>
bool	operator<=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
{ return !(rhs < lhs); }

template<class T1, class T2>
bool	operator>(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
{ return rhs < lhs; }

template<class T1, class T2>
bool	operator>=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
{ return !(lhs < rhs); }


/* **************************************** */
/* Creates ft::pair object, deducing the    */
/* target type from the types of arguments. */
/* **************************************** */
template<class T1, class T2>
ft::pair<T1, T2>	make_pair(T1 a, T2 b)
{ return ft::pair<T1, T2>(a, b); }



template<class InputIter1, class InputIter2>
bool lexicographical_compare(InputIter1 first1, InputIter1 last1,
							InputIter2 first2, InputIter2 last2) {

	for (; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return ((first1 == last1) && (first2 != last2));
}


template<class InputIter1, class InputIter2>
bool	equal(InputIter1 first1, InputIter1 last1,
			InputIter2 first2) {

	for (; first1 != last1; ++first1, ++first2)
		if (*first1 != *first2)
			return false;
	return true;
}


}

#endif // UTILITY_H
