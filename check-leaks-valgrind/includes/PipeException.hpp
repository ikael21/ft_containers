#ifndef PIPE_EXCEPTION_H
# define PIPE_EXCEPTION_H
# include <exception>

class PipeException : public std::exception {

	virtual const char*	what(void) const throw() {
		return "pipe: could not init pipe buffer";
	}

};

#endif
