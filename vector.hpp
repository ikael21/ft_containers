#ifndef VECTOR_H
# define VECTOR_H
# include <memory>
# include <stdexcept>
# include "iterators/iterator.hpp"

namespace ft {


template <class T, class Allocator = std::allocator<T> >
class vector {

public:

	typedef T														value_type;
	typedef Allocator												allocator_type;
	typedef typename allocator_type::size_type						size_type;
	typedef typename allocator_type::difference_type				difference_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef typename ft::iterator_traits<pointer>::pointer			iterator;
	typedef typename ft::iterator_traits<const_pointer>::pointer	const_iterator;
/*
	typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
*/

	explicit vector(const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr) {}

	explicit vector(size_type count, const value_type& value = value_type(),
					const allocator_type& alloc = allocator_type())
	: _alloc(alloc) {
		_start = _alloc.allocate(count);
		for (std::size_t i = 0; i < count; ++i)
			_start[i] = value;
		_end = _start + count;
		_end_capacity = _start + count;
		return;
	}

/*
	template<class InputIt>
	vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type());
*/

/* need to change when iterators implementation is done */
	vector(const vector& other)
	: _alloc(other._alloc), _start(nullptr) { *this = other; }

	~vector(void) { _alloc.deallocate(_start, capacity()); }

/* need to change when iterators implementation is done */
	vector&	operator=(const vector& other) {
		if (this == &other)
			return *this;
		_alloc.deallocate(_start, capacity());
		_alloc = other._alloc;
		_start = _alloc.allocate(other.capacity());
		for (std::size_t i = 0; i < other.size(); ++i)
			_start[i] = other._start[i];
		_end = _start + other.size();
		_end_capacity = _start + other.capacity();
		return *this;
	}

	/* ***************************** */
	/*     ELEMENT ACCESS METHODS    */
	/* ***************************** */
	const_reference		operator[](size_type pos) const { return *(_start + pos); }
	reference			operator[](size_type pos) { return *(_start + pos); }

	const_reference		at(size_type pos) const {
		if (!(pos < size()))
			throw std::out_of_range("out of range");
		return *(_start + pos);
	}

	reference			at(size_type pos) {
		if (!(pos < size()))
			throw std::out_of_range("out of range");
		return *(_start + pos);
	}

	reference			front(void) { return _start[0]; }
	const_reference		front(void) const { return _start[0]; }
	reference			back(void) { return _start[size() - 1]; }
	const_reference		back(void) const { return _start[size() - 1]; }
	value_type*			data(void) { return _start; }
	const value_type*	data(void) const { return _start; }

	/* ***************************** */
	/*         ITERATORS             */
	/* ***************************** */
	iterator	begin(void) { return _start; }
	iterator	end(void) { return _end; }

	/* ***************************** */
	/*           CAPACITY            */
	/* ***************************** */
	bool		empty(void) const { return (_start == _end); }
	size_type	size(void) const { return (_end - _start); }
	size_type	max_size(void) const { return _alloc.max_size(); }

	void		reserve(size_type new_cap) {
		if (!(new_cap <= capacity())) {
			pointer	_tmp = _alloc.allocate(new_cap);
			for (std::size_t i = 0; i < size(); ++i)
				_tmp[i] = _start[i];
			_alloc.deallocate(_start, capacity());
			_start = _tmp;
		}
	}

	std::size_t	capacity(void) const { return (_end_capacity - _start); }

protected:

	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	pointer			_end_capacity;

};

}

#endif // VECTOR_H
