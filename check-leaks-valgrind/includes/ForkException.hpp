#ifndef FORK_EXCEPTION_H
# define FORK_EXCEPTION_H
# include <exception>

class ForkException : public std::exception {

	virtual const char*	what(void) const throw() {
		return "fork: could not create a child process";
	}

};

#endif
