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
	TreeElement<Sort, Object>* previous;
	string previousChild;
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
		TreeElement<Sort, Object>* newElement = new TreeElement<Sort, Object>(element, 0, 0);
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

	bool remove(Sort sortField) {
		this->current = this->top;
		this->previous = 0;
		while (this->current != 0) {
			if (this->getSortField(this->current->getData()->at(0)) > sortField) {
				if (this->current->hasRight()) {
					this->previous = this->current;
					this->previousChild = "right";
					this->current = this->current->getRightChild();
				}
				else {
					return false;
				}
			}
			else if (this->getSortField(this->current->getData()->at(0)) < sortField){
				if (this->current->hasLeft()) {
					this->previous = this->current;
					this->previousChild = "left";
					this->current = this->current->getLeftChild();
				}
				else {
					return false;
				}
			}
			else {
				this->isExist = true;
				if (!this->current->hasLeft() && !this->current->hasRight()){
					if (this->previousChild == "left") {
						this->previous->setLeftChild(0);
					}
					else {
						this->previous->setRightChild(0);
					}
					delete this->current;
				}
				else if (!this->current->hasRight() && this->current->hasLeft()) {
					this->current->setData(this->current->getLeftChild()->getData());
					this->current->setLeftChild(this->current->getLeftChild()->getRightChild());
					this->current->setRightChild(this->current->getLeftChild()->getLeftChild());
				}
				else if (!this->current->hasLeft() && this->current->hasRight()) {
					this->current->setData(this->current->getRightChild()->getData());
					this->current->setLeftChild(this->current->getRightChild()->getRightChild());
					this->current->setRightChild(this->current->getRightChild()->getLeftChild());
				}
				else {
					TreeElement<Sort, Object>* tempElem = this->current->getLeftChild();
					while (tempElem->hasLeft()) {
						tempElem = tempElem->getLeftChild();
					}
					this->current->setData(this->current->getRightChild()->getData());
					tempElem->setLeftChild(this->current->getLeftChild());
					this->current->setLeftChild(tempElem);
					this->current->setRightChild(this->current->getRightChild()->getRightChild());
				}
				return true;
			}
		}		
	}

	bool edit(Sort sortField, Object* newData) {
		if (this->getSortField(newData) != sortField) {
			if (this->remove(sortField)) {
				this->add(newData);
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return this->find(sortField, [&newData](TreeElement<Sort, Object>* treeElement, bool isExist, string child) -> void {
				if (isExist) {
					for (int i = 0; i < treeElement->getData()->size(); ++i)
					{
						Student::edit(treeElement->getData()->at(i), newData);
					}
				}
			});
		}
	}


	vector<Object*>* findByIndex(Sort sort) {
		vector<Object*>* result = new vector<Object*>();
		this->find(sort, [&result](TreeElement<Sort, Object>* treeElem, bool isExist, string child) -> void {
			if (isExist) {
				result = treeElem->getData();
			}
		});
		return result;		
	}
	bool find(Sort index, function<void(TreeElement<Sort, Object>*, bool, string )> callback) {
		this->current = this->top;
		this->previous = 0;
		while (this->current != 0) {
			if (this->getSortField(this->current->getData()->at(0)) > index) {
				if (this->current->hasRight()) {
					this->previous = this->current;
					this->current = this->current->getRightChild();
				}
				else {
					callback(this->current, false, "right");
					return false;
				}
			}
			else if (this->getSortField(this->current->getData()->at(0)) < index){
				if (this->current->hasLeft()) {
					this->previous = this->current;
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

