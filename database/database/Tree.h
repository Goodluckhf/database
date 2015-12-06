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
			this->find(sortField, [&element, &newElement](TreeElement<Sort, Object>* treeElement, bool isExist, string child, TreeElement<Sort, Object>* prev, TreeElement<Sort, Object>* top) -> void{
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
		return this->find(sortField, [](TreeElement<Sort, Object>* treeElement, bool isExist, string child, TreeElement<Sort, Object>* prev, TreeElement<Sort, Object>* top) -> void {
			if (isExist) {
				if (!treeElement->hasLeft() && !treeElement->hasRight()){
					treeElement = 0;
				}
				else if (!treeElement->hasRight() && treeElement->hasLeft()) {
					if (prev == 0) {
						top->setLeftChild(treeElement->getLeftChild());
					}
					else {
						prev = treeElement->getLeftChild();
					}
					//treeElement = treeElement->getLeftChild();
				}
				else if (!treeElement->hasLeft() && treeElement->hasRight()) {
					treeElement = treeElement->getRightChild();
				}
				else {
					TreeElement<Sort, Object>* tempElem = treeElement->getRightChild();
					while (tempElem->hasRight()) {
						tempElem = tempElem->getRightChild();
					}
					treeElement = new TreeElement<Sort, Object>(treeElement->getData(), treeElement->getLeftChild(), tempElem);
				}
			}
		});
	}

	bool Tree<Sort, Object>::edit(Sort sortField, Object* newData) {
		return this->find(sortField, [&newData](TreeElement<Sort, Object>* treeElement, bool isExist, string child, TreeElement<Sort, Object>* prev, TreeElement<Sort, Object>* top) -> void {
			if (isExist) {
				for (int i = 0; i < treeElement->getData->size(); ++i)
				{
					Student::edit(treeElement->getData->at(i), newData);
				}
			}
		});
	}


	vector<Object*>* findByIndex(Sort sort) {
		vector<Object*>* result = new vector<Object*>();
		this->find(sort, [&result](TreeElement<Sort, Object>* treeElem, bool isExist, string child, TreeElement<Sort, Object>* prev, TreeElement<Sort, Object>* top) -> void {
			if (isExist) {
				result = treeElem->getData();
			}
		});
		return result;		
	}
	bool find(Sort index, function<void(TreeElement<Sort, Object>*, bool, string, TreeElement<Sort, Object>*, TreeElement<Sort, Object>* )> callback) {
		this->current = this->top;
		this->previous = 0;
		while (this->current != 0) {
			if (this->getSortField(this->current->getData()->at(0)) > index) {
				if (this->current->hasRight()) {
					this->previous = this->current;
					this->current = this->current->getRightChild();
				}
				else {
					callback(this->current, false, "right", this->previous, this->top);
					return false;
				}
			}
			else if (this->getSortField(this->current->getData()->at(0)) < index){
				if (this->current->hasLeft()) {
					this->previous = this->current;
					this->current = this->current->getLeftChild();
				}
				else {
					callback(this->current, false, "left", this->previous, this->top);
					return false;
				}
			}
			else {
				this->isExist = true;
				callback(this->current, true, "", this->previous, this->top);
				return true;
			}
		}
		
		return true;
	}


};

