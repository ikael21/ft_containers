#include "tests_includes.hpp"

typedef system_clock::time_point	t_time;

/* ******************************** */
/* returns the execution time of    */
/* the given pointer to a function  */
/* in microseconds                  */
/* ******************************** */
size_t	measure_time(void (*func)(void)) {

	t_time	start, end;

	start = high_resolution_clock::now();
	func();
	end = high_resolution_clock::now();
	return (duration_cast<microseconds>(end - start).count());
}
