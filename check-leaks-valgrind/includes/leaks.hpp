#ifndef LEAKS_H
# define LEAKS_H

# include <vector>
# include <string>
# include <cstring>
# include <fstream>
# include <iostream>
# include <unistd.h>
# include <cstdlib>
# include <sys/wait.h>

# include "ForkException.hpp"
# include "FileException.hpp"
# include "PipeException.hpp"
# include "ReadException.hpp"


// change if path is different from this
# define VALGRIND_PATH	"/usr/bin/valgrind"

# define BUFFER_SIZE	1000
# define LEAK_SUM		"LEAK SUMMARY:"
# define HEAP_SUM		"HEAP SUMMARY:"
# define DEF_LOST_MEM	"definitely lost:"

// colors for beauty
# define MAGENTA	"\033[35;1m"
# define YELLOW		"\033[33;1m"
# define RESET		"\033[0m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"

typedef std::vector<std::string>	string_vector;


std::string		get_valgrind_info(const char*);
void			execute_valgrind(int*, string_vector const&);
std::string		read_info(int);
string_vector	parse_info(std::string& info);
void			save_info(string_vector const& info_vec);
void			print_info(string_vector const& info_vec);


#endif
