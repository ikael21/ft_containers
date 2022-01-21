#ifndef TYPE_TRAITS_H
# define TYPE_TRAITS_H


namespace ft {


/* ******************************************* */
/* a template struct to conditionally remove   */
/* functions from the candidate set based      */
/* on type traits                              */
/* ******************************************* */
template<bool B, class T = void>
struct enable_if {};


/* **************************************************** */
/* Specialization to add functions to the candidate set */
/* **************************************************** */
template<class T>
struct enable_if<true, T> { typedef T type; };


/* ***************************************** */
/* Base class for is_integral struct         */
/* wraps a static constant of specified type */
/* ***************************************** */
template<class T, T v>
struct integral_constant {

	static const bool value = v;
	typedef T value_type;
	typedef integral_constant type;
	operator value_type() const { return value; }

};


/* ****************************************** */
/* Bool variants of integral_constant struct  */
/* ****************************************** */
typedef ft::integral_constant<bool, true>	true_type;
typedef ft::integral_constant<bool, false>	false_type;


/* ************************************ */
/* struct to check if T - integral type */
/* ************************************ */
template<class T>
struct is_integral : public ft::false_type {};


/* ************************************************* */
/* Specializations of all fundamental integral types */
/* ************************************************* */
template<> struct is_integral<bool> : public ft::true_type {};
template<> struct is_integral<char> : public ft::true_type {};
template<> struct is_integral<unsigned char> : public ft::true_type {};
template<> struct is_integral<wchar_t> : public ft::true_type {};
template<> struct is_integral<short int> : public ft::true_type {};
template<> struct is_integral<int> : public ft::true_type {};
template<> struct is_integral<unsigned int> : public ft::true_type {};
template<> struct is_integral<long int> : public ft::true_type {};
template<> struct is_integral<unsigned short int> : public ft::true_type {};
template<> struct is_integral<unsigned long int> : public ft::true_type {};


}

#endif
