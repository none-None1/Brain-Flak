#pragma once
#include "parse.h"
#include "debugger.h"
template<typename inttype> inttype run(vector<node> &tree, int root, int wrapped, stack<inttype> &left, stack<inttype> &right, bool &current, bool debug) { // Interpret Brain-Flak from the tree
	if (debug) debug_stack(left, right, current);
	stack<inttype> *st = &(current ? right : left);
	if (root==-1) {
		switch (wrapped) {
		case PARENTHESIS: {
			return inttype(1);
		}
		case SQUARE_BRACKET: {
			return inttype(st->size());
		}
		case CURLY_BRACKET: {
			if (st->empty()) return 0;
			inttype x = st->top();
			st->pop();
			return x;
		}
		case TRIANGULAR_BRACKET: {
			current = !current;
			return 0;
		}
		}
	}
	switch (wrapped) {
	case PARENTHESIS: {
		inttype sum = 0;
		for (int i = 0; i < tree[root].childs.size(); i++) {
			sum += run(tree, tree[root].childs[i].id, tree[root].childs[i].type, left, right, current, debug);
			st = &(current ? right : left);
		}
		st->push(sum);
		return sum;
	}
	case SQUARE_BRACKET: {
		inttype sum = 0;
		for (int i = 0; i < tree[root].childs.size(); i++) {
			sum += run(tree, tree[root].childs[i].id, tree[root].childs[i].type, left, right, current, debug);
		}
		return -sum;
	}
	case CURLY_BRACKET: {
		inttype sum = 0;
		while (!st->empty() && st->top()) {
			//std::cout << st.top() << std::endl;
			for (int i = 0; i < tree[root].childs.size(); i++) {
				sum += run(tree, tree[root].childs[i].id, tree[root].childs[i].type, left, right, current, debug);
				st = &(current ? right : left);
			}
		}
		return sum;
	}
	default: {
		for (int i = 0; i < tree[root].childs.size(); i++) {
			run(tree, tree[root].childs[i].id, tree[root].childs[i].type, left, right, current, debug);
		}
		return 0;
	}
	}
}