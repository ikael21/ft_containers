#include "stack.hpp"

int	main(void) {
	
	std::stack<int>	stack1;
	std::stack<int>	stack2;

	stack1.push(10);

	stack2 = stack1;

	std::stack<int>	stack3(stack1);
}
