# FT_CONTAINERS

Objective of the project is to get familiar with
`the standard C++ template library`
by recoding some of the STL containers.

*All the code was written according to С++98 Standard*

### [Vector](https://cplusplus.com/reference/vector/vector/)
```
template <class T, class Allocator = std::allocator<T> >
class vector;
```

### [Stack](https://cplusplus.com/reference/stack/stack/)
```
template<class T, class Container = std::deque<T> >
class stack;
```

### [Map](https://cplusplus.com/reference/map/map)
```
template <
  class Key,
  class T, class Compare = std::less<Key>,
  class Allocator = std::allocator<std::pair<const Key, T> >
>
class map;
```

### [Set](https://cplusplus.com/reference/set/set)
```
template <
  class Key,
  class Compare = std::less<Key>,
  class Allocator = std::allocator<Key>
>
class set;
```
