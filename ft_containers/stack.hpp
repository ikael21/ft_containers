#ifndef STACK_H
# define STACK_H
# include "vector.hpp"

namespace ft {


template<class T, class Container = ft::vector<T> >
class stack {

public:

	typedef T											value_type;
	typedef Container									container_type;
	typedef typename container_type::size_type			size_type;
	typedef typename container_type::reference			reference;
	typedef typename container_type::const_reference	const_reference;

	explicit stack(const container_type& cont = container_type()) : c(cont) {}
	stack(const stack& other) : c(other.c) {}
	~stack() {}

	stack&	operator=(const stack& other) {
		if (this != &other)
			c = other.c;
		return *this;
	}

	void			push(const value_type& value) { c.push_back(value); }
	void			pop(void) { c.pop_back(); }
	bool			empty(void) const { return c.empty(); }
	size_type		size(void) const { return c.size(); }
	reference		top(void) { return c.back(); }
	const_reference	top(void) const { return c.back(); }

	template<class U, class ContainerU>
	friend bool	operator==(const ft::stack<U, ContainerU>&, const ft::stack<U, ContainerU>&);

	template<class U, class ContainerU>
	friend bool	operator!=(const ft::stack<U, ContainerU>&, const ft::stack<U, ContainerU>&);

	template<class U, class ContainerU>
	friend bool	operator<(const ft::stack<U, ContainerU>&, const ft::stack<U, ContainerU>&);

	template<class U, class ContainerU>
	friend bool	operator<=(const ft::stack<U, ContainerU>&, const ft::stack<U, ContainerU>&);

	template<class U, class ContainerU>
	friend bool	operator>(const ft::stack<U, ContainerU>&, const ft::stack<U, ContainerU>&);

	template<class U, class ContainerU>
	friend bool	operator>=(const ft::stack<U, ContainerU>&, const ft::stack<U, ContainerU>&);

protected:

	container_type	c;

};


template<class T, class Container>
bool	operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return (lhs.c == rhs.c); }

template<class T, class Container>
bool	operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return (lhs.c != rhs.c); }

template<class T, class Container>
bool	operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return (lhs.c < rhs.c); }

template<class T, class Container>
bool	operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return (lhs.c <= rhs.c); }

template<class T, class Container>
bool	operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return (lhs.c > rhs.c); }

template<class T, class Container>
bool	operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{ return (lhs.c >= rhs.c); }

}

#endif
