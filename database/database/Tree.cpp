#include "Tree.h"

template<class Sort, class Object>
Tree<Sort, Object>::Tree(Sort(sortCallback*)(Object*)) {
	this->current = 0;
	this->top = 0;
	this->getSortField = sortCallback;
	this->isExist = false;
}	



template<class Sort, class Object>
bool Tree<Sort, Object>::find(Sort index, void (callback*) (TreeElement<Sort, Object>*, string)) {
	this->current = this->top;
	while(this->current != 0) {
		if (this->getSortField(this->current->getData) > index) {
			if (this->current->hasRight()) {
				this->current = this->current->getRightChild();
			}
			else {
				callback(this->current, "right");
				return false;
			}
		}
		else if (this->getSortField(this->current->getData) < index){
			if (this->current->hasLeft()) {
				this->current = this->current->getLeftChild();
			}
			else {
				callback(this->current, "left");
				return false;
			}
		}
		else {
			this->isExist = true;
			return true;
		}
	}
}

template<class Sort, class Object>
Tree<Sort, Object>::add(Object* element) {
	TreeElement<Object>* newElement = new TreeElement<Object>(element);
	Sort sortField = this->getSortField(element);
	if (this->top == 0) {
		this->top = newElement;
	}
	else {
		this->find(sortField, [](treeElement, child) -> {
			if (this->isExist) {
				//tekywii
			}
			else if (child == "left") {
				treeElemnt->setLeftChild(newElement);
			}
			else {
				treeElemnt->setRightChild(newElement);
			}
		});
		
	}
	return sortField;
}

