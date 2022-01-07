#ifndef VECTOR_H
# define VECTOR_H
# include <memory>
# include <stdexcept>
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
	typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
*/

	explicit vector(const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _start(nullptr), _size(0), _capacity(0) {}

	explicit vector(size_type count, const value_type& value = value_type(),
					const allocator_type& alloc = allocator_type())
	: _alloc(alloc) {
		if (!count)
			default_init();
		else {
			_start = _alloc.allocate(count);
			for (size_type i = 0; i < count; ++i)
				_start[i] = value;
			_size = count;
			_capacity = _size;
		}
	}

/*
	template<class InputIt>
	vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type());
*/



/*
	need to change when iterators implementation is done
*/
	vector(const vector& other) {
		_alloc = other._alloc;
		if (!other.size())
			default_init();
		else {
			_start = _alloc.allocate(other.capacity());
			for(size_type i = 0; i < other._size; ++i)
				_start[i] = other._start[i];
			_size = other._size;
			_capacity = other._capacity;
		}
	}

	~vector() { clear(); _alloc.deallocate(_start, capacity()); }

/*
	need to change when iterators implementation is done
*/
	vector&	operator=(const vector& other) {
		if (this == &other)
			return *this;
		_alloc.deallocate(_start, capacity());
		_alloc = other._alloc;
		if (!other.size())
			default_init();
		else {
			_start = _alloc.allocate(other.capacity());
			for (std::size_t i = 0; i < other.size(); ++i)
				_start[i] = other._start[i];
			_size = other._size;
			_capacity = other._capacity;
		}
		return *this;
	}

	allocator_type	get_allocator(void) const { return _alloc; }


	/* ***************************** */
	/*         ELEMENT ACCESS        */
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

	const_reference		front(void) const { return _start[0]; }
	reference			front(void) { return _start[0]; }

	const_reference		back(void) const { return _start[size() - 1]; }
	reference			back(void) { return _start[size() - 1]; }

	const value_type*	data(void) const { return _start; }
	value_type*			data(void) { return _start; }


	/* ***************************** */
	/*         ITERATORS             */
	/* ***************************** */
	iterator		begin(void) { return iterator(_start); }
	const_iterator	begin(void) const { return iterator(_start); }

	iterator		end(void) { return iterator(_start + size()); }
	const_iterator	end(void) const { return iterator(_start + size()); }


	/* ***************************** */
	/*           CAPACITY            */
	/* ***************************** */
	bool		empty(void) const { return (!size()); }
	size_type	size(void) const { return _size; }
	size_type	max_size(void) const { return _alloc.max_size(); }

	void		reserve(size_type new_cap) {
		if (new_cap > _capacity) {
			pointer	tmp = _alloc.allocate(new_cap);
			for (size_type i = 0; i < _size; ++i)
				tmp[i] = _start[i];
			_alloc.deallocate(_start, capacity());
			_start = tmp;
			_capacity = new_cap;
		}
	}

	size_type	capacity(void) const { return _capacity; }


	/* ************************* */
	/*         MODIFIERS         */
	/* ************************* */
	void	clear(void) {
		for(size_type i = 0; i < _size; ++i)
			_alloc.destroy(_start + i);
		_size = 0;
	}

/*
	iterator	insert(iterator pos, const_reference value) {
		if (size() == capacity())
			(!capacity()) ? reserve(1) : reserve(capacity() * 2);
	}
*/

	void	push_back(const_reference value) {
		if (size() == capacity())
			(!capacity()) ? reserve(1) : reserve(capacity() * 2);
		_start[size()] = value;
		_size++;
	}

protected:

	allocator_type	_alloc;
	pointer			_start;
	size_type		_size;
	size_type		_capacity;

private:

	void	default_init(void) {
		_start = nullptr;
		_size = 0;
		_capacity = 0;
	}

};

}

#endif // VECTOR_H
