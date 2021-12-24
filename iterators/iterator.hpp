#ifndef ITERATOR_H
# define ITERATOR_H
# include <cstddef>

namespace ft {


/* ************************* */
/*   CATEGORIES OF ITERATOR  */
/* ************************* */
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};


/* *************************** */
/* INTERFACE TO THE PROPERTIES */
/* OF ITERATOR TYPES           */
/* *************************** */
template<class Iterator>
struct iterator_traits {

	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;

};


/* ****************************** */
/* T* specialization member types */
/* ****************************** */
template<class T>
struct iterator_traits<T*> {

	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ft::random_access_iterator_tag	iterator_category;

};


/* ************************* */
/* const T* specialization   */
/* member types              */
/* ************************* */
template<class T>
struct iterator_traits<const T*> {

	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef ft::random_access_iterator_tag	iterator_category;

};


/* ************************* */
/*    BASE ITERATOR CLASS    */
/* ************************* */
template<class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T&>
struct iterator {

	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;

};


}

#endif
