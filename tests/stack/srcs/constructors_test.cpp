#include "tests_includes.hpp"


static void	test1(void) {

	const size_t	COUNT = 100;
	ft::stack<int>	st;
	ft::vector<int>	vec;

	for (size_t i = 0; i < 100 * COUNT; ++i)
		vec.push_back(static_cast<int>(i));

	for (size_t i = 0; i < 200 * COUNT; ++i)
		st.push(static_cast<int>(i));

	ft::stack<int>	stack1(vec);
	ft::stack<int>	stack2(stack1);

	ft::stack<int>	stack3;
	stack3 = stack2;

	while (stack1.size() > 0)
		stack1.pop();
	while (stack2.size() > 0)
		stack2.pop();
	while (stack3.size() > 0)
		stack3.pop();
	while (stack3.size() < COUNT * COUNT)
		stack3.push(10);
	print << "END\n";
}

void	run_constructor_test(void) {

	print << MAGENTA "CONSTRUCTORS TESTS: ";
	test1();
	print << RESET LF;
}
