#ifndef UTILITY_H
# define UTILITY_H

namespace ft {


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


template<class ForwardIter, class T>
void	fill(ForwardIter first, ForwardIter last, const T& value) {
	while (first != last)
		*first = value;
}

template<class OutputIter, class Size, class T>
void	fill_n(OutputIter first, Size count, const T& value) {
	for (Size i = 0; i < count; ++i, ++first)
		*first = value;
}


}

#endif // UTILITY_H
