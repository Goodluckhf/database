#pragma once
#include "Student.h"
#include "TreeElement.h"


template <class Sort, class Object>
class Tree {
private:
	TreeElement<Sort, Object>* top;
	TreeElement<Sort, Object>* current;
	Sort(*getSortField)(Object*);
	bool isExist;
public:
	Tree<Sort, Object>(Sort(*sortCallback)(Object*)) {
		this->current = 0;
		this->top = 0;
		this->getSortField = sortCallback;
		this->isExist = false;
	}
	Sort add(Object*);
	bool remove(Sort);
	bool edit(Sort, Object*);
	bool find(Sort, void (*) (TreeElement<Sort, Object>*, string));

};

