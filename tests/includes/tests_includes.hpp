#ifndef TESTS_INCLUDES_H
# define TESTS_INCLUDES_H

# include <iostream>
# include <sstream>
# include <vector>
# include <chrono>
# include "vector.hpp"


// for time measuring
using namespace std::chrono;

# define TEST_VECTOR	ft::vector
# define print			std::cout
# define LF				"\n"

struct A {

	A() : _n(new char()) {}

	A(const A& o) : _n(new char(*o._n)) {}

	A&	operator=(const A&o) {
		delete _n;
		_n = new char(*o._n);
		return *this;
	}

	~A() { delete _n; }

	bool	operator!=(const A&) const { return false; }

private:

	char*	_n;

};


#define SMALL_COUNT	100000

// short types for vectors and their iterators
typedef std::vector<A>				std_vector;
typedef std_vector::const_iterator	RandIter;
typedef TEST_VECTOR<A>				ft_vector;


// stl vector to compare the test one with
static std_vector	g_vecToCompare(SMALL_COUNT);
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
void	run_insert_test(void);
void	run_assign_test(void);
void	run_constructor_test(void);
void	run_pop_back_test(void);
void	run_push_back_test(void);


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
