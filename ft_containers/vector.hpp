#ifndef VECTOR_H
# define VECTOR_H
# include "memory/ft_uninitialized.hpp"
# include <algorithm>
# include <stdexcept>
# include <ext/alloc_traits.h>
# include "utility/type_traits.hpp"
# include "iterators/iterator.hpp"


namespace ft {


template <class T, class Allocator = std::allocator<T> >
class vector {

public:

	typedef T													value_type;
	typedef Allocator											allocator_type;
	typedef typename allocator_type::size_type					size_type;
	typedef typename allocator_type::difference_type			difference_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
	typedef typename ft::RandomAccessIterator<value_type>		iterator;
	typedef typename ft::RandomAccessIterator<const value_type>	const_iterator;
/*
	typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
*/

	explicit vector(const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _start(NULL), _size(0), _capacity(0) {}


	explicit vector(
		size_type count,
		const value_type& value = value_type(),
		const allocator_type& alloc = allocator_type()
	)
	: _alloc(alloc), _start(NULL), _size(count), _capacity(count) {

		if (count > 0) {
			_start = _alloc.allocate(count);
			try
			{ ft::uninitialized_fill_a(_start, _start + count, value, _alloc); }
			catch (...)
			{ _alloc.deallocate(_start, count); throw; }
		}
	}


	template<class InputIt>
	vector(
		InputIt __first,
		typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type __last,
		const allocator_type& alloc = allocator_type()
	)
	: _alloc(alloc), _start(NULL), _size(0), _capacity(0)
	{ assign(__first, __last); }


	vector(const vector& o)
	: _alloc(o.get_allocator()), _start(NULL), _size(0), _capacity(0)
	{ assign(o.begin(), o.end()); }


	~vector() { clear(); _alloc.deallocate(_start, _capacity); }


	vector&	operator=(const vector& other) {
		if (this != &other)
			assign(other.begin(), other.end());
		return *this;
	}

	allocator_type	get_allocator(void) const { return _alloc; }

	void	assign(size_type count, const_reference value) {

		if (count > _capacity) {
			vector	tmp(count, value, _alloc);
			tmp.swap(*this);
		}
		else if (count > _size) {
			std::fill(_start, _start + _size, value);
			const size_type diff = count - _size;
			ft::uninitialized_fill_n_a(_start + _size,
				diff, value, _alloc);
			_size += diff;
		}
		else {
			std::fill_n(_start, count, value);
			for (size_t i = count; i < _size; ++i)
				_alloc.destroy(_start + i);
			_size = count;
		}
	}

	template<class InputIt>
	typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type
	assign(InputIt __first, InputIt __last) {

		size_type new_cap = __last - __first;
		size_type i = 0;

		reserve(new_cap);
		while (i < _size and __first != __last) {
			_start[i] = *__first;
			++i; ++__first;
		}
		ft::uninitialized_copy_a(__first, __last, _start + i, _alloc);
		while (i < _size) {
			_alloc.destroy(_start + i);
			++i;
		}

		_size = new_cap;
	}


	/* ***************************** */
	/*         ELEMENT ACCESS        */
	/* ***************************** */
	const_reference	operator[](size_type pos) const { return *(_start + pos); }
	reference		operator[](size_type pos) { return *(_start + pos); }

	const_reference	at(size_type pos) const {
		if (!(pos < _size))
			throw std::out_of_range("out of range");
		return *(_start + pos);
	}

	reference		at(size_type pos) {
		if (!(pos < _size))
			throw std::out_of_range("out of range");
		return *(_start + pos);
	}

	const_reference		front(void) const { return _start[0]; }
	reference			front(void) { return _start[0]; }

	const_reference		back(void) const { return _start[_size - 1]; }
	reference			back(void) { return _start[_size - 1]; }

	const value_type*	data(void) const { return _start; }
	value_type*			data(void) { return _start; }


	/* ***************************** */
	/*         ITERATORS             */
	/* ***************************** */
	iterator		begin(void) { return iterator(_start); }
	const_iterator	begin(void) const { return const_iterator(_start); }

	iterator		end(void) { return iterator(_start + _size); }
	const_iterator	end(void) const { return const_iterator(_start + _size); }


	/* ***************************** */
	/*           CAPACITY            */
	/* ***************************** */
	bool		empty(void) const { return (!_size); }
	size_type	size(void) const { return _size; }
	size_type	max_size(void) const { return _alloc.max_size(); }

	void	reserve(size_type new_cap) {

		if (new_cap > max_size())
			throw std::length_error("vector::reserve");

		if (new_cap > _capacity) {

			pointer	tmp = _alloc.allocate(new_cap);

			try
			{ ft::uninitialized_copy_a(begin(), end(), tmp, _alloc); }
			catch (...)
			{ _alloc.deallocate(tmp, new_cap); throw; }

			for (size_type i = 0; i < _size; ++i)
				_alloc.destroy(_start + i);
			_alloc.deallocate(_start, _capacity);

			_start = tmp;
			_capacity = new_cap;
		}
	}

	size_type	capacity(void) const { return _capacity; }


	/* ************************* */
	/*         MODIFIERS         */
	/* ************************* */
	void	clear(void) {
		for (size_type i = 0; i < _size; ++i)
			_alloc.destroy(_start + i);
		_size = 0;
	}

	iterator	insert(iterator pos, const_reference value) {

		size_type index = pos - begin();

		if (_size == _capacity)
			(!_capacity) ? reserve(1) : reserve(_capacity * 2);

		_alloc.construct(_start + _size, _start[_size - 1]);
		size_type i = _size - 1;
		for (; i > index; --i)
			_start[i] = _start[i - 1];

		_start[i] = value;
		_size++;
		return iterator(begin() + index);
	}

	void	insert(iterator pos, size_type count,
					const_reference value) {
		if (!count)
			return;

		size_type index = pos - begin();
		size_type new_size = _size + count;

		if (count >= _capacity)
			reserve(new_size);
		else if (new_size > _capacity) {
			size_type new_cap = (!_capacity) ? 1 : _capacity;
			while (new_cap < new_size)
				new_cap *= 2;
			reserve(new_cap);
		}

		for (size_type i = _size - 1; i >= index; --i)
			_alloc.construct(_start + i + count, _start[i]);

		for (size_type i = 0; i < count; ++i)
			_alloc.construct(_start + i + index, value);

//		could change to code below instead of for() loop above
//		std::uninitialized_fill(_start + index, _start + count, value);
		_size = new_size;
	}

	void	push_back(const_reference value) {
		if (_size == _capacity)
			(!_capacity) ? reserve(1) : reserve(_capacity * 2);
		_alloc.construct(_start + _size, value);
		_size++;
	}

	void	pop_back(void)
	{ --_size; _alloc.destroy(_start + _size); }


	void	resize(size_type count, value_type value = value_type()) {

		if (count < _size) {
			while (count < _size)
				pop_back();
			return;
		}

		if (count > _size) {
			size_type new_cap = _capacity * 2;
			if (new_cap < count)
				new_cap = count;
			reserve(new_cap);
			for (; _size < count; ++_size)
				_alloc.construct(_start + _size, value);
		}
	}

	void	swap(vector& other) {
		std::swap(_alloc, other._alloc);
		std::swap(_start, other._start);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
	}

private:

	allocator_type	_alloc;
	pointer			_start;
	size_type		_size;
	size_type		_capacity;

};


template<class T, class Allocator = std::allocator<T> >
void	swap(ft::vector<T, Allocator>& x, ft::vector<T, Allocator>& y)
{ x.swap(y); }


}

#endif // VECTOR_H
