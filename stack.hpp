#ifndef STACK_H
# define STACK_H
# include <memory>

// delete after implementing own vector
# include <vector>

namespace ft {

template<class T, class Container = std::vector<T> >
class stack {

public:

	typedef T											value_type;
	typedef Container									container_type;
	typedef typename container_type::size_type			size_type;
	typedef typename container_type::reference			reference;
	typedef typename container_type::const_reference	const_reference;

	explicit stack(const container_type& cont = container_type()) : _cont(cont) {}
	stack(const stack& other) { *this = other; }
	~stack() {}

	stack&	operator=(const stack& other) {
		if (this == other)
			return *this;
		_cont = other._cont;
		return *this;
	}

	void			push(const value_type& value) { _cont.push_back(value); }
	void			pop(void) { _cont.pop_back(); }
	bool			empty(void) const { return _cont.empty(); }
	size_type		size(void) const { return _cont.size(); }
	reference		top(void) { return _cont.back(); }
	const_reference	top(void) const { return _cont.back(); }

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

	container_type	_cont;

};

template<class T, class Container>
bool	operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
	return (lhs._cont == rhs._cont);
}

template<class T, class Container>
bool	operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
	return (lhs._cont != rhs._cont);
}

template<class T, class Container>
bool	operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
	return (lhs._cont < rhs._cont);
}

template<class T, class Container>
bool	operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
	return (lhs._cont <= rhs._cont);
}

template<class T, class Container>
bool	operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
	return (lhs._cont > rhs._cont);
}

template<class T, class Container>
bool	operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
	return (lhs._cont >= rhs._cont);
}

}

#endif
