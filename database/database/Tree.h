#pragma once
#include "TreeElement.h"

template <class Sort, class Object>
class Tree {
private:
	TreeElement<Sort, Object>* top;
	TreeElement<Sort, Object>* current;
	Sort(*)(Object*) getSortField;
	bool isExist;
public:
	Tree<Sort, Object>(Sort(*)(Object*));
	int add(Object*);
	bool remove(Sort);
	bool edit(Sort, Object*);
	bool find(Sort index, void (*) (TreeElement<Sort, Object>*, string));

};

