#ifndef READ_EXCEPTION_H
# define READ_EXCEPTION_H
# include <exception>

class ReadException : public std::exception {

	virtual const char*	what(void) const throw() {
		return "read: could not read from the given FD";
	}

};

#endif
