#include "leaks.hpp"

std::string	read_info(int read_fd) {

	std::string	info;
	char		*buffer;
	ssize_t		bytes_num;

	buffer = new char[BUFFER_SIZE + 1];
	std::memset(buffer, '\0', BUFFER_SIZE + 1);

	bytes_num = read(read_fd, buffer, BUFFER_SIZE);
	while (bytes_num > 0) {
		buffer[bytes_num] = '\0';
		info += buffer;
		bytes_num = read(read_fd, buffer, BUFFER_SIZE);
	}

	if (bytes_num == -1) {
		close(read_fd);
		throw ReadException();
	}

	return info;
}
