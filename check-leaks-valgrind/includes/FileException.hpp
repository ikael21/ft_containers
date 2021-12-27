#ifndef FILE_EXCEPTION_H
# define FILE_EXCEPTION_H
# include <exception>

class FileException : public std::exception {

	virtual const char*	what(void) const throw() {
		return "ofstream: could not open/create a log file (valgrind_log)";
	}

};

#endif
