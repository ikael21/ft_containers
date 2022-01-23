#ifndef TESTS_INCLUDES_H
# define TESTS_INCLUDES_H

# include <iostream>
# include <vector>
# include <chrono>
# include "vector.hpp"


// for time measuring
using namespace std::chrono;

# define TEST_VECTOR	ft::vector


# define print		std::cout
# define STD_VEC	"std::vector"
# define FT_VEC		"ft::vector"
# define LF			"\n"
# define MAX_RAM	4294967296
# define BUF_SIZE	4096

struct Buffer {
	int idx;
	char buff[BUF_SIZE];
};

#define COUNT		(MAX_RAM / (int)sizeof(Buffer))
#define SMALL_COUNT	100000
#define TEST_STRING	"string"

// short types for vectors and their iterators
typedef std::vector<std::string>	std_vector;
typedef std_vector::const_iterator	RandIter;
typedef TEST_VECTOR<std::string>	ft_vector;


// stl vector to compare the test one with
const std_vector	g_vecToCompare(SMALL_COUNT, TEST_STRING);
const RandIter		g_begin = g_vecToCompare.begin();
const RandIter		g_end = g_vecToCompare.end();

/* ************************* */
/*     colors for beauty     */
/* ************************* */
# define MAGENTA	"\033[35;1m"
# define YELLOW		"\033[33;1m"
# define RESET		"\033[0m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"


/* ************************* */
/*      TEST FUNCTIONS       */
/* ************************* */
void	run_iterator_test(void);
void	speed_test(void);
void	run_insert_tests(void);
void	run_assign_test(void);
void	run_constructor_test(void);
void	pop_back_test(void);


/* ************************* */
/*         UTILITY           */
/* ************************* */

size_t	measure_time(void (*)(void));


/* ******************************************************** */
/* Cont1 and Cont2 must have size() and capacity() methods! */
/* ******************************************************** */
template<class Cont1, class Cont2>
bool	compare_size_cap(const Cont1& c1, const Cont2& c2) {
	return (c1.size() == c2.size() and c1.capacity() == c2.capacity());
}


/* ********************************************************************* */
/* Cont1 and Cont2 must have iterator system, begin() and end() methods! */
/* ********************************************************************* */
template<class Cont1, class Cont2>
bool	is_conts_equal(const Cont1& v1, const Cont2& v2) {

	typedef typename Cont1::const_iterator	iter_one;
	typedef typename Cont2::const_iterator	iter_two;

	iter_one iter1 = v1.begin();
	iter_two iter2 = v2.begin();
	while (iter1 != v1.end() or iter2 != v2.end()) {
		if (*iter1 != *iter2)
			return false;
		++iter1, ++iter2;
	}
	return (iter1 == v1.end() and iter2 == v2.end());
}

#endif
