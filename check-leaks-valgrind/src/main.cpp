#include "leaks.hpp"

static void	usage(void) {
	std::cout << MAGENTA "		Usage" << std::endl;
	std::cout << YELLOW "./check_leaks";
	std::cout << " path_to_bin [bin_args]" RESET << std::endl;
}

static void	run_test(char *bin_args[]) {

	std::string		info;
	string_vector	result_info;

	try { info = get_valgrind_info(bin_args); }
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	if (!info.length()) {
		std::cerr << RED "valgrind executing error" << std::endl;
		std::cerr << YELLOW "check if valgrind exists"
			<< MAGENTA " (" << VALGRIND_PATH ")" << std::endl;
		std::cerr << YELLOW "check if the given binary exists"
			<< MAGENTA " (" << bin_args[0] << ")" << std::endl;
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

	if (argc == 1) {
		usage();
		return EXIT_SUCCESS;
	}
	run_test(argv + 1);
	return EXIT_SUCCESS;
}
