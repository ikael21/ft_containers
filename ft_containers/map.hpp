#ifndef MAP_H
# define MAP_H
# include <functional>
# include <memory>
# include <utility>
# include "utility/type_traits.hpp"
# include "utility/utility.hpp"
# include "utility/red_black_tree.hpp"

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
/*
	value_compare
*/
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
/*
	iterators
*/
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
/*
	size_type
*/

private:

	typedef typename allocator_type::rebind<ft::node<value_type>>::other	_alloc_node_type;

};


}



#endif // MAP_H
