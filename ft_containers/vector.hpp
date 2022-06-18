#ifndef VECTOR_H
# define VECTOR_H
# include <stdexcept>
# include <algorithm>
# include "utility/uninitialized_memory.hpp"
# include "utility/type_traits.hpp"
# include "utility/algorithm.hpp"
# include "utility/iterator.hpp"


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
	typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;


	explicit vector(
		const allocator_type& alloc = allocator_type()
	)
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
	{ this->assign(__first, __last); }


	vector(const vector& o)
	: _alloc(o.get_allocator()), _start(NULL), _size(0), _capacity(0)
	{ this->assign(o.begin(), o.end()); }


	~vector() { this->clear(); _alloc.deallocate(_start, _capacity); }


	vector&	operator=(const vector& other) {
		if (this != &other)
			this->assign(other.begin(), other.end());
		return *this;
	}

	allocator_type	get_allocator(void) const { return _alloc; }

	void	assign(size_type count, const_reference value) {

		if (count > _capacity) {
			vector	tmp(count, value, _alloc);
			tmp.swap(*this);
		}
		else if (count > _size) {
			ft::fill(_start, _start + _size, value);
			const size_type diff = count - _size;
			ft::uninitialized_fill_n_a(_start + _size,
				diff, value, _alloc);
			_size += diff;
		}
		else {
			ft::fill_n(_start, count, value);
			for (size_t i = count; i < _size; ++i)
				_alloc.destroy(_start + i);
			_size = count;
		}
	}

	template<class InputIt>
	typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type
	assign(InputIt __first, InputIt __last) {

		size_type new_cap = static_cast<size_type>(ft::distance(__first, __last));
		size_type i = 0;

		this->reserve(new_cap);
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
	iterator				begin(void) { return iterator(_start); }
	const_iterator			begin(void) const { return const_iterator(_start); }

	reverse_iterator		rbegin() { return reverse_iterator(iterator(_start + _size - 1)); }
	const_reverse_iterator	rbegin() const { return const_reverse_iterator(iterator(_start + _size - 1)); }

	iterator				end(void) { return iterator(_start + _size); }
	const_iterator			end(void) const { return const_iterator(_start + _size); }

	reverse_iterator 		rend() { return reverse_iterator(iterator(_start)); }
	const_reverse_iterator	rend() const { return const_reverse_iterator(iterator(_start)); }


	/* ***************************** */
	/*           CAPACITY            */
	/* ***************************** */
	bool		empty(void) const { return (!_size); }
	size_type	size(void) const { return _size; }
	size_type	max_size(void) const { return _alloc.max_size(); }

	void	reserve(size_type new_cap) {

		if (new_cap > this->max_size())
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

	iterator	erase(iterator pos) {

		const size_type index = static_cast<size_type>(pos - this->begin());

		size_type i = index;
		for (; i < _size - 1; ++i)
			_start[i] = _start[i + 1];

		_alloc.destroy(_start + i);
		--_size;

		return iterator(_start + index);
	}

	iterator	erase(iterator first, iterator last) {

		const size_type index = static_cast<size_type>(first - this->begin());
		const size_type count = static_cast<size_type>(last - first);

		if (count > 0) {
			size_type i = index;
			for (; i < _size - count; ++i)
				_start[i] = _start[i + count];
			for (; i < _size; ++i)
				_alloc.destroy(_start + i);
			_size -= count;
		}
		return iterator(_start + index);
	}

	template<class InputIt>
	typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type
	insert(iterator pos, InputIt first, InputIt last) {

		const size_type count = static_cast<size_type>(last - first);
		if (count > 0) {

			const size_type new_size = _size + count;
			if (new_size <= _capacity) {

				iterator current = this->end() - 1;
				try {
					for (; current != pos - 1 && current + count >= this->end(); --current)
						_alloc.construct(&(*(current + count)), *current);
				}
				catch (...) {
					for (iterator it = this->end(); it != current; --it)
						_alloc.destroy(&(*(it + count)));
					throw;
				}
				for (; current != pos - 1; --current)
					*(current + count) = *current;

				const size_type n = static_cast<size_type>(pos - this->begin());
				size_type i = 0;
				for (; first != last && i + n < this->size(); ++i, ++first)
					_start[i + n] = *first;

				size_type ex = i;
				try {
					for (; first != last; ++i, ++first)
						_alloc.construct(_start + i + n, *first);
				}
				catch (...) {
					for (; ex < i; ++ex)
						_alloc.destroy(_start + ex + n);
					throw;
				}

				_size = new_size;

			}
			else {
				const size_type new_cap = this->__recommend_size(new_size);
				pointer tmp = _alloc.allocate(new_cap);

				try
				{ ft::uninitialized_copy_a(this->begin(), pos, tmp, _alloc); }
				catch (...)
				{ _alloc.deallocate(tmp, new_cap); throw; }

				const size_type _n = static_cast<size_type>(pos - this->begin());
				try
				{ ft::uninitialized_copy_a(first, last, tmp + _n, _alloc); }
				catch(...) {
					for (size_type i = 0; i < _n; ++i)
						_alloc.destroy(tmp + i);
					_alloc.deallocate(tmp, new_cap);
					throw;
				}

				try {
					ft::uninitialized_copy_a(pos, this->end(),
						tmp + _n + count, _alloc);
				}
				catch (...) {
					for (size_type i = 0; i < _n + count; ++i)
						_alloc.destroy(tmp + i);
					_alloc.deallocate(tmp, new_cap);
					throw;
				}

				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_start + i);
				_alloc.deallocate(_start, _capacity);

				_start = tmp;
				_size = new_size;
				_capacity = new_cap;
			}
		}
	}

	iterator	insert(iterator pos, const_reference value) {

		size_type index = static_cast<size_type>(pos - this->begin());

		if (_size == _capacity)
			this->reserve(this->__recommend_size(_size + 1));

		_alloc.construct(_start + _size, _start[_size - 1]);
		size_type i = _size;
		for (; i > index; --i)
			_start[i] = _start[i - 1];

		_start[i] = value;
		_size++;
		return iterator(begin() + index);
	}

	void	insert(iterator pos, size_type count, const_reference value) {

		if (count > 0) {

			const size_type new_size = _size + count;
			if (new_size <= _capacity) {

				iterator current = this->end();
				try {
					for (; current != pos - 1 && current + count >= this->end(); ++current)
						_alloc.construct(&(*(current + count)), *current);
				}
				catch (...) {
					for (iterator it = this->end(); it != current; --it)
						_alloc.destroy(&(*(it + count)));
					throw;
				}
				for (; current != pos - 1; --current)
					*(current + count) = *current;

				const size_type n = static_cast<size_type>(pos - this->begin());
				size_type i = 0;
				for (; i < count && i + n < this->size(); ++i)
					_start[i + n] = value;

				size_type ex = i;
				try {
					for (; i < count; ++i)
						_alloc.construct(_start + i + n, value);
				}
				catch (...) {
					for (; ex < i; ++ex)
						_alloc.destroy(_start + ex + n);
					throw;
				}

				_size = new_size;

			}
			else {
				const size_type new_cap = this->__recommend_size(new_size);
				pointer tmp = _alloc.allocate(new_cap);

				try
				{ ft::uninitialized_copy_a(this->begin(), pos, tmp, _alloc); }
				catch (...)
				{ _alloc.deallocate(tmp, new_cap); throw; }

				const size_type _n = static_cast<size_type>(pos - this->begin());
				try
				{ ft::uninitialized_fill_n_a(tmp + _n, count, value, _alloc); }
				catch(...) {
					for (size_type i = 0; i < _n; ++i)
						_alloc.destroy(tmp + i);
					_alloc.deallocate(tmp, new_cap);
					throw;
				}

				try {
					ft::uninitialized_copy_a(pos, this->end(),
						tmp + _n + count, _alloc);
				}
				catch (...) {
					for (size_type i = 0; i < _n + count; ++i)
						_alloc.destroy(tmp + i);
					_alloc.deallocate(tmp, new_cap);
					throw;
				}

				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_start + i);
				_alloc.deallocate(_start, _capacity);

				_start = tmp;
				_size = new_size;
				_capacity = new_cap;
			}
		}
	}

	void	push_back(const_reference value) {
		if (_size == _capacity)
			this->reserve(this->__recommend_size(_size + 1));
		_alloc.construct(_start + _size, value);
		_size++;
	}

	void	pop_back(void)
	{ --_size; _alloc.destroy(_start + _size); }


	void	resize(size_type count, value_type value = value_type()) {

		if (count < _size) {
			while (count < _size)
				this->pop_back();
			return;
		}

		if (count > _size) {
			if (_capacity < count)
				this->reserve(this->__recommend_size(count));
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

	/**
	 * if new_s > _capacity
	**/
	size_type	__recommend_size(size_type new_s) {

		const size_type max_s = this->max_size();
		if (new_s > max_s)
			throw std::length_error("vector");
		if (_capacity >= max_s / 2)
			return max_s;

		const size_type new_cap = _capacity * 2;
		return (new_cap > new_s) ? new_cap : new_s;
	}


	allocator_type	_alloc;
	pointer			_start;
	size_type		_size;
	size_type		_capacity;

};


/**
 * Relational operators (vector)
**/
template<class T, class Alloc>
bool	operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{ return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

template <class T, class Alloc>
inline bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return !(lhs == rhs); }

template<class T, class Alloc>
inline bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

template<class T, class Alloc>
inline bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return !(rhs < lhs); }

template<class T, class Alloc>
inline bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return rhs < lhs; }

template<class T, class Alloc>
inline bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return !(lhs < rhs); }


}


namespace std {


/**
 * Specializes the std::swap algorithm for ft::vector
 * Swaps the contents of lhs and rhs.
**/
template<class T, class Allocator>
void	swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs)
{ lhs.swap(rhs); }


}

#endif // VECTOR_H
