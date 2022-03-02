#ifndef MAP_H
# define MAP_H
# include <functional>
# include <memory>
# include <utility>
# include "utility/type_traits.hpp"
# include "utility/utility.hpp"

namespace ft {


template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key, T> >
>
class map {

};

}



#endif // MAP_H
