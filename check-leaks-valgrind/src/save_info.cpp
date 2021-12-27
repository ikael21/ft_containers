#include "leaks.hpp"


void	save_info(string_vector const& info_vec) {

	std::ofstream		log_file("valgrind_logs");

	if (!log_file.is_open())
		throw FileException();
	log_file << info_vec[0] << info_vec[1];
	log_file.close();
}
