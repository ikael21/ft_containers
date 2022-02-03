#include "tests_includes.hpp"

typedef system_clock::time_point	t_time;

/* ******************************** */
/* returns the execution time of    */
/* the given pointer to a function  */
/* in microseconds                  */
/* ******************************** */
template<class Function>
size_t	measure_time(Function* f) {

	t_time	start, end;

	start = high_resolution_clock::now();
	f();
	end = high_resolution_clock::now();
	return (duration_cast<microseconds>(end - start).count());
}
