#include "leaks.hpp"

/* *************************************** */
/* execute valgrind as child proccess      */
/* and get output info through pipe buffer */
/* *************************************** */
std::string	get_valgrind_info(const char* bin_name) {

	string_vector	exec_args;
	pid_t			child_pid;
	int				pipe_fd[2];
	int				status;

	if (pipe(pipe_fd) == -1)
		throw PipeException();
	exec_args.push_back("/usr/bin/valgrind");
	exec_args.push_back("--leak-check=full");
	exec_args.push_back(bin_name);

	child_pid = fork();
	if (child_pid == -1) {
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		throw ForkException();
	}
	if (!child_pid)
		execute_valgrind(pipe_fd, exec_args);
	close(pipe_fd[1]);
	std::string info(read_info(pipe_fd[0]));
	close(pipe_fd[0]);

	waitpid(child_pid, &status, 0);
	if (WEXITSTATUS(status) > 0)
		info.clear();
	return info;
}
