#pragma once
#include <vector>
#include "Student.h"
using namespace std;

template <class Sort, class Object>
class TreeElement {
private:
	TreeElement<Sort, Object>* leftChild;
	TreeElement<Sort, Object>* rightChild;
	vector<Object*>* data;

public:
	/*
	TreeElement(Object*, TreeElement<Sort, Object>*, TreeElement<Sort, Object>*);
	TreeElement(Object*);
	TreeElement();
	vector<Object*>* getData();
	TreeElement<Sort, Object>* getLeftChild();
	TreeElement<Sort, Object>* getRightChild();
	void setData(Object* data);
	void setLeftChild(TreeElement<Sort, Object>* child);
	void setRightChild(TreeElement<Sort, Object>* child);
	bool hasLeft();
	bool hasRight();
	*/

















	TreeElement(Object* element, TreeElement<Sort, Object>* leftChild, TreeElement<Sort, Object>* rightChild) {
		this->data = new vector<Object*>();
		this->data->push_back(element);
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}

	TreeElement(Object* element) {
		TreeElement(element, 0, 0);
	}

	TreeElement() {
		TreeElement(0, 0, 0);
	}
	
	vector<Object*>* getData() {
		return this->data;
	}

	
	TreeElement<Sort, Object>* getLeftChild() {
		return this->leftChild;
	}

	
	TreeElement<Sort, Object>* getRightChild() {
		return this->rightChild;
	}

	
	void setData(Object* data) {
		this->data = data;
	}

	
	void setLeftChild(TreeElement<Sort, Object>* child) {
		this->leftChild = child;
	}

	
	void setRightChild(TreeElement<Sort, Object>* child) {
		this->rightChild = child;
	}

	
	bool hasLeft() {
		return this->leftChild != 0;
	}

	
	bool hasRight() {
		return this->rightChild != 0;
	}
};

