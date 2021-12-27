#include "leaks.hpp"

static void	remove_all_substr(std::string& str,
						std::string const pattern) {

	size_t	i;

	i = str.find(pattern);
	while (i != std::string::npos) {
		str.erase(i, pattern.length());
		i = str.find(pattern, i);
	}
}

string_vector	parse_info(std::string& info) {

	size_t			pos;
	string_vector	result_info;

	remove_all_substr(info,
		info.substr(0, info.find(" ") + 1));

	pos = info.find(LEAK_SUM);
	result_info.push_back(info.substr(0, pos));
	result_info[0].erase(0, info.find(HEAP_SUM));

	result_info.push_back(info.substr(pos));
	result_info[1].erase(result_info[1].find("\n\n"));

	info.clear();

	return result_info;
}
