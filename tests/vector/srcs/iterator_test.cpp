#include "tests_includes.hpp"

typedef std::vector<int>	std_v;
typedef std_v::iterator		std_i;

typedef ft::vector<int>		ft_v;
typedef ft_v::iterator		ft_i;

template<class Container>
void	iterator_test1(const char* cont_name) {

	typedef typename Container::iterator	iter;

	Container	cont;
	iter		i;

	print << YELLOW "Iterator test: number + iter ---- " GREEN
		<< cont_name << RESET LF;
	fill_in_container(cont);
	i = (MAX_ITEMS / 2) + cont.begin();
	print << *i << LF;
}

template<class Container>
void	iterator_test2(const char* cont_name) {

	typedef typename Container::iterator	iter;

	Container	cont;
	iter		i;

	print << YELLOW "Iterator test: iter + number ---- " GREEN
		<< cont_name << RESET LF;
	fill_in_container(cont);
	i = cont.begin() + (MAX_ITEMS / 2);
	print << *i << LF;
}

void	run_iterator_test(void) {

	/* ********************** */
	/*  iter = number + iter  */
	/* ********************** */
	iterator_test1<std_v>(STD_VEC);
	iterator_test1<ft_v>(FT_VEC);


	/* ********************** */
	/*  iter = iter + number  */
	/* ********************** */
	iterator_test2<std_v>(STD_VEC);
	iterator_test2<ft_v>(FT_VEC);


	ft_v	ft_vec;

	try {
		ft_vec.reserve(ft_vec.max_size() + 1);
	}
	catch (std::length_error& e) {
		std::cout << e.what() << std::endl;
	}
}
