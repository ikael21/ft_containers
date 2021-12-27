#include "leaks.hpp"

void	execute_valgrind(int* pipe_fd, string_vector const& args) {

	char**					argv;
	std::allocator<char*>	alloc;

	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDERR_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pipe_fd[1]);

	argv = alloc.allocate(args.size() + 1);
	for(size_t i = 0; i < args.size(); ++i)
		argv[i] = (char *)args[i].c_str();

	argv[args.size()] = NULL;

	execve(argv[0], argv, NULL);
	std::cerr << "execve error: "
		<< strerror(errno) <<  std::endl;
	exit(EXIT_FAILURE);
}
