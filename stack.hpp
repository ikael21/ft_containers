#ifndef STACK_H
# define STACK_H
# include <memory>
# include <stack>
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

	explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {}
	stack(const stack& other) {
		*this = other;
	}

	stack&	operator=(const stack& other) {
		_ctnr = other._cntr;
		return *this;
	}





protected:

	container_type	_ctnr;

};


}

#endif
