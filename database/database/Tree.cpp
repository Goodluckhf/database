#include "Tree.h"

template<class Sort, class Object>
bool Tree<Sort, Object>::find(Sort index, void (*callback) (TreeElement<Sort, Object>*, bool, string)) {
	this->current = this->top;
	while(this->current != 0) {
		if (this->getSortField(this->current->getData) > index) {
			if (this->current->hasRight()) {
				this->current = this->current->getRightChild();
			}
			else {
				callback(this->current, false, "right");
				return false;
			}
		}
		else if (this->getSortField(this->current->getData) < index){
			if (this->current->hasLeft()) {
				this->current = this->current->getLeftChild();
			}
			else {
				callback(this->current, false, "left");
				return false;
			}
		}
		else {
			this->isExist = true;
			callback(this->current, true, "");
			return true;
		}
	}
}

template<class Sort, class Object>
Sort Tree<Sort, Object>::add(Object* element) {
	TreeElement<Object>* newElement = new TreeElement<Object>(element);
	Sort sortField = this->getSortField(element);
	if (this->top == 0) {
		this->top = newElement;
	}
	else {
		this->find(sortField, [](treeElement, isExist, child) -> {
			if (isExist) {
				treeElement->getData()->push_back(element);
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

template<class Sort, class Object>
bool Tree<Sort, Object>::remove(Sort sortField) {
	return this->find(sortField, [](treeElement, isExist, child) -> {
		if (isExist) {
			if (!treeElement->hasLeft() && !treeElement->hasRight()){
				treeElement = 0;
			}
			else if (!treeElement->hasRight() && treeElement->hasLeft()) {
				treeElement = treeElement->getLeftChild();
			}
			else if (!treeElement->hasLeft() && treeElement->hasRight()) {
				treeElement = treeElement->getRightChild();
			}
			else {
				TreeElement<Sort, Object> tempElem = treeElement->getRightChild();
				while (tempElem->hasRight()) {
					tempElem = tempElem->getRightChild();
				}
				treeElement = new TreeElement(treeElement->getData(), treeElement->getLeftChild(), tempElem);
			}
		}
	});	
}

template<class Sort, class Object>
bool Tree<Sort, Object>::edit(Sort sortField, Object newData) {
	return this->find(sortField, [](treeElement, isExist, child) -> {
		if (isExist) {
			std::list<Object*>::iterator it = treeElement->getData->begin();
			for (; it != treeElement->getData->end(); ++it)
			{
				Student::edit(it, newData);
			}
		}
	});
}