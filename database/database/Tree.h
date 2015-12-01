#pragma once
#include "Student.h"
#include "TreeElement.h"
#include <functional>
using std::tr1::function;

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
	Sort add(Object* element) {
		TreeElement<Sort, Object>* newElement = new TreeElement<Sort, Object>(element);
		Sort sortField = this->getSortField(element);
		if (this->top == 0) {
			this->top = newElement;
		}
		else {
			this->find(sortField, [&element, &newElement](TreeElement<Sort, Object>* treeElement, bool isExist, string child) -> void{
				if (isExist) {
					treeElement->getData()->push_back(element);
				}
				else if (child == "left") {
					treeElement->setLeftChild(newElement);
				}
				else {
					treeElement->setRightChild(newElement);
				}
			});
		}
		return sortField;
	}
	bool remove(Sort);

	bool edit(Sort, Object*);

	vector<Object*>* findByIndex(Sort sort) {
		vector<Object*>* result;
		if (this->find(sort, [&result](TreeElement<Sort, Object>* treeElem, bool isExist, string child) -> void {
			if (isExist) {
				result = treeElem->getData();
			}
		})) {
			return result;
		}
	}
	//bool find(Sort, void (*) (TreeElement<Sort, Object>*, bool, string));
	bool find(Sort index, function<void(TreeElement<Sort, Object>*, bool, string)> callback) {
		this->current = this->top;
		while (this->current != 0) {
			if (this->getSortField(this->current->getData()->at(0)) > index) {
				if (this->current->hasRight()) {
					this->current = this->current->getRightChild();
				}
				else {
					callback(this->current, false, "right");
					return false;
				}
			}
			else if (this->getSortField(this->current->getData()->at(0)) < index){
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
		
		return true;
	}


};

