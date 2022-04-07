#ifndef MAP_H
# define MAP_H
# include <functional>
# include <memory>
# include <utility>
# include "utility/type_traits.hpp"
# include "utility/algorithm.hpp"
# include "utility/pair.hpp"


namespace ft {


template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key, T> >
>
class map {

public:

	typedef Key											key_type;
	typedef T											mapped_type;
	typedef ft::pair<const key_type, mapped_type>		value_type;
	typedef Compare										key_compare;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

/*
	iterators

	difference_type

	size_type
*/

	/**
	 * A function object that compares objects of type
	 * ft::map::value_type (key-value pairs) by comparing
	 * of the first components of the pairs.
	**/
	class value_compare
	: public std::binary_function<value_type, value_type, bool> {

		friend class ft::map;

	protected:

		value_compare(key_compare c) : comp(c) {}

		bool operator()(const_reference x, const_reference y) const
		{ return comp(x.first, y.first); }

		key_compare	comp;

	};

private:

	typedef typename allocator_type::rebind</* node type */>::other	_alloc_node_type;


};


}



#endif // MAP_H
