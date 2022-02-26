#ifndef ITERATOR_H
# define ITERATOR_H
# include <cstddef>
# include <iterator>

namespace ft {


/* ************************* */
/*   CATEGORIES OF ITERATOR  */
/* ************************* */
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};


/* *************************** */
/* INTERFACE TO THE PROPERTIES */
/* OF ITERATOR TYPES           */
/* *************************** */
template<class Iterator>
struct iterator_traits {

	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;

};


/* ****************************** */
/* T* specialization member types */
/* ****************************** */
template<class T>
struct iterator_traits<T*> {

	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ft::random_access_iterator_tag	iterator_category;

};


/* ************************* */
/* const T* specialization   */
/* member types              */
/* ************************* */
template<class T>
struct iterator_traits<const T*> {

	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef ft::random_access_iterator_tag	iterator_category;

};

/* ************************* */
/* for do_distance function  */
/* ************************* */
namespace detail {


/* ****************************************************** */
/* if Iter meets the requirements of InputIterator        */
/* ****************************************************** */
template<class Iter>
typename ft::iterator_traits<Iter>::difference_type
do_distance(Iter first, Iter last, ft::input_iterator_tag) {

	typename ft::iterator_traits<Iter>::difference_type diff = 0;
	while (first != last) {
		++first;
		++diff;
	}
	return diff;
}

template<class Iter>
typename ft::iterator_traits<Iter>::difference_type
do_distance(Iter first, Iter last, std::input_iterator_tag) {

	typename ft::iterator_traits<Iter>::difference_type diff = 0;
	while (first != last) {
		++first;
		++diff;
	}
	return diff;
}


/* ****************************************************** */
/* if Iter meets the requirements of RandomAccessIterator */
/* ****************************************************** */
template<class Iter>
typename ft::iterator_traits<Iter>::difference_type
do_distance(Iter first, Iter last, ft::random_access_iterator_tag) {
	return last - first;
}

template<class Iter>
typename ft::iterator_traits<Iter>::difference_type
do_distance(Iter first, Iter last, std::random_access_iterator_tag) {
	return last - first;
}


}


/* ************************* */
/* THE SAME AS STD::DISTANCE */
/* ************************* */
template<class Iter>
typename ft::iterator_traits<Iter>::difference_type
distance(Iter first, Iter last) {
	return ft::detail::do_distance(first, last,
		typename ft::iterator_traits<Iter>::iterator_category());
}


template<class T>
class RandomAccessIterator {

public:

	/* ************************* */
	/*     ITERATOR TYPES        */
	/* ************************* */
	typedef	typename ft::iterator_traits<T*>::iterator_category	iterator_category;
	typedef	typename ft::iterator_traits<T*>::value_type		value_type;
	typedef	typename ft::iterator_traits<T*>::difference_type	difference_type;
	typedef	typename ft::iterator_traits<T*>::pointer			pointer;
	typedef	typename ft::iterator_traits<T*>::reference			reference;


	explicit RandomAccessIterator(pointer const ptr = NULL)
	: _ptr(ptr) {}

	RandomAccessIterator(const RandomAccessIterator& other)
	: _ptr(other._ptr) {}


	/* ************************* */
	/*   ASSIGNMENT OPERATORS    */
	/* ************************* */
	RandomAccessIterator&	operator=(const RandomAccessIterator& other) {
		_ptr = other._ptr;
		return *this;
	}

	RandomAccessIterator&	operator+=(difference_type n) { _ptr += n; return *this; }
	RandomAccessIterator&	operator-=(difference_type n) { _ptr -= n; return *this; }


	/* ******************************* */
	/* INCREMENT / DECREMENT OPERATORS */
	/* ******************************* */
	RandomAccessIterator&	operator++(void) { ++_ptr; return *this; }
	RandomAccessIterator&	operator--(void) { --_ptr; return *this; }

	RandomAccessIterator	operator++(int) {
		RandomAccessIterator copy(*this);
		++_ptr;
		return copy;
	}

	RandomAccessIterator	operator--(int) {
		RandomAccessIterator copy(*this);
		--_ptr;
		return copy;
	}


	/* ************************* */
	/*   ARITHMETIC OPERATORS    */
	/* ************************* */
	RandomAccessIterator	operator+(difference_type n) const {
		return RandomAccessIterator(_ptr + n);
	}

	RandomAccessIterator	operator-(difference_type n) const {
		return RandomAccessIterator(_ptr - n);
	}

	difference_type			operator-(const RandomAccessIterator& other) const {
		return _ptr - other._ptr;
	}


	/* ************************* */
	/*  MEMBER ACCESS OPERATORS  */
	/* ************************* */
	reference	operator*(void) { return *_ptr; };
	reference	operator[](difference_type n) { return *(_ptr + n); }
	pointer		operator->(void) const { return _ptr; }
	pointer		base(void) const { return _ptr; }


private:

	pointer	_ptr;

};


template<class T>
inline RandomAccessIterator<T>	operator+(
			const typename RandomAccessIterator<T>::difference_type& n,
			const RandomAccessIterator<T>& iter)
{ return RandomAccessIterator<T>(iter + n); }


template<class Iterator>
class reverse_iterator {

public:

	typedef Iterator													iterator_type;
	typedef	typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef	typename ft::iterator_traits<Iterator>::value_type			value_type;
	typedef	typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	typedef	typename ft::iterator_traits<Iterator>::pointer				pointer;
	typedef	typename ft::iterator_traits<Iterator>::reference			reference;


	reverse_iterator()
	: _iter() {}

	explicit reverse_iterator(iterator_type it)
	: _iter(it) {}

	template<class U>
	reverse_iterator(const reverse_iterator<U>& rev_it)
	: _iter(rev_it.base()) {}

	reference			operator*() const {
		iterator_type tmp = _iter;
		return (*(--tmp));
	}

	reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_iter - n); }
	reverse_iterator&	operator+=(difference_type n) { _iter -= n; return *this; }
	reverse_iterator&	operator++() { --_iter; return *this; }
	reverse_iterator	operator++(int) {
		reverse_iterator it(*this);
		--_iter;
		return it;
	}


	reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_iter + n); }
	reverse_iterator&	operator-=(difference_type n) { _iter += n; return *this; }
	reverse_iterator&	operator--() { ++_iter; return *this; }
	reverse_iterator	operator--(int) {
		reverse_iterator it(*this);
		++_iter;
		return it;
	}

	pointer				operator->() const { return &(this->operator*()); }
	reference			operator[](difference_type n) const { return _iter[n]; }
	iterator_type		base() const { return _iter; }

private:

	Iterator	_iter;

};


/* ********************************************** */
/* Non-member reverse_iterator function overloads */
/* ********************************************** */
template <class Iterator>
reverse_iterator<Iterator> operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it)
{ return rev_it + n; }

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
{ return lhs.base() - rhs.base(); }


/* *********************************************************************** */
/* template comparison operators for compatibility with std. iterators or  */
/* iterators of different type (Bedirectional, Forward, ...)               */
/* *********************************************************************** */
template<typename _LeftIterator, typename _RightIterator>
inline bool	operator==(const _LeftIterator& lhs, const _RightIterator& rhs)
{ return (lhs.base() == rhs.base()); }

template<typename _LeftIterator, typename _RightIterator>
inline bool	operator!=(const _LeftIterator& lhs, const _RightIterator& rhs)
{ return (lhs.base() != rhs.base()); }

template<typename _LeftIterator, typename _RightIterator>
inline bool	operator>=(const _LeftIterator& lhs, const _RightIterator& rhs)
{ return (lhs.base() >= rhs.base()); }

template<typename _LeftIterator, typename _RightIterator>
inline bool	operator<=(const _LeftIterator& lhs, const _RightIterator& rhs)
{ return (lhs.base() <= rhs.base()); }

template<typename _LeftIterator, typename _RightIterator>
inline bool	operator>(const _LeftIterator& lhs, const _RightIterator& rhs)
{ return (lhs.base() > rhs.base()); }

template<typename _LeftIterator, typename _RightIterator>
inline bool	operator<(const _LeftIterator& lhs, const _RightIterator& rhs)
{ return (lhs.base() < rhs.base()); }


}

#endif
