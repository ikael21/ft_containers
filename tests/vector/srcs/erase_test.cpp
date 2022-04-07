#include "tests_includes.hpp"

struct B {

	B() : _n(new char()) {}

	B(const B& o) : _n(new char(*o._n)) {}

	B&	operator=(const B&o) {
		delete _n;
		_n = new char(*o._n);
		print << "B =\n";
		return *this;
	}

	~B() { delete _n; print << "B ends\n"; }

	bool	operator!=(const B&) const { return false; }

private:

	char*	_n;

};

static void	test1(void) {

	std::string			result;
	ft::vector<int>		test_vec(10);
	std::vector<int>	std_vec(10);

	ft::vector<int>::iterator it1 = test_vec.erase(test_vec.begin(), test_vec.begin());
	std::vector<int>::iterator it2 =std_vec.erase(std_vec.begin(), std_vec.begin());
	const ft::vector<int>::difference_type diff1 = it1 - test_vec.begin();
	const std::vector<int>::difference_type diff2 = it2 - std_vec.begin();

	if (compare_size_cap(test_vec, std_vec) && diff1 == diff2
		&& is_conts_equal(test_vec, std_vec))
		result = GREEN ".";
	else
		result = RED "F";
	print << result;
}

void	run_erase_test(void) {

	print << MAGENTA "ERASE TESTS: ";
	test1();
	print << RESET LF;
}
