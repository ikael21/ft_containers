#include "leaks.hpp"

static void	run_test(const char* bin_name) {

	std::string		info;
	string_vector	result_info;

	try { info = get_valgrind_info(bin_name); }
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	if (!info.length()) {
		std::cerr << "valgrind executing error" << std::endl;
		std::cerr << "check if valgrind exists ("
			 << VALGRIND_PATH ")" << std::endl;
		std::cerr << "check if the given binary exists ("
			<< bin_name << ")" << std::endl;
		exit(EXIT_FAILURE);
	}
	result_info = parse_info(info);
	try { save_info(result_info); }
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	print_info(result_info);
}

int	main(int argc, char* argv[]) {

	std::string		info;
	string_vector	result_info;

	if (argc != 2)
		return EXIT_SUCCESS;
	run_test(argv[1]);
	return EXIT_SUCCESS;
}
