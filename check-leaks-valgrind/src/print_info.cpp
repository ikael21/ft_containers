#include "leaks.hpp"

void	print_info(string_vector const& info_vec) {

	int					bytes_num;
	size_t				pos;
	std::string			def_lost;
	std::string const&	leak_sum = info_vec[1];

	pos = leak_sum.find(DEF_LOST_MEM);
	def_lost = leak_sum.substr(pos + std::string(DEF_LOST_MEM).length());
	bytes_num = std::atoi(def_lost.c_str());

	if (bytes_num > 0) {
		std::cout << RED DEF_LOST_MEM RESET
			<< def_lost.substr(0, def_lost.find("\n"))
			<< std::endl;
	}
	else {
		std::cout << GREEN
			<< "There is no definitely lost memory" RESET
			<< std::endl;
	}

	std::cout << YELLOW
		<< "See [valgrind_logs] file for more detailed info"
	RESET << std::endl;
}
