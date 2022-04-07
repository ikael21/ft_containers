#ifndef RB_TREE_H
# define RB_TREE_H
# include <iterator>
# include "pair.hpp"

namespace ft {


enum rb_tree_color {
	red = false,
	black = true
};


struct rb_tree_node_base {

	typedef rb_tree_node_base*			base_ptr;
	typedef const rb_tree_node_base*	const_base_ptr;

	rb_tree_color	color;
	base_ptr		parent;
	base_ptr		left;
	base_ptr		right;

	static base_ptr minimum(base_ptr x) {
		while (x->left) x = x->left;
		return x;
	}

	static const_base_ptr minimum(const_base_ptr x) {
		while (x->left) x = x->left;
		return x;
	}

	static base_ptr	maximum(base_ptr x) {
		while (x->right) x = x->right;
		return x;
	}

	static const_base_ptr maximum(const_base_ptr x) {
		while (x->right) x = x->right;
		return x;
	}

};


template<class Key, class T>
struct rb_tree_map_node : public rb_tree_node_base {

	typedef rb_tree_map_node<Key, T>*	link_type;
	typedef ft::pair<const Key, T>*		value_ptr;

	value_ptr	value;

};


}

#endif // RB_TREE_H
