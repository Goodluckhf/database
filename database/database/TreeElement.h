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
	TreeElement(Object* element, TreeElement<Sort, Object>* leftChild, TreeElement<Sort, Object>* rightChild) {
		this->data = new vector<Object*>();
		this->data->push_back(element);
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}

	TreeElement(vector<Object*>* element, TreeElement<Sort, Object>* leftChild, TreeElement<Sort, Object>* rightChild) {
		//this->data = new vector<Object*>();
		this->data = element;
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}

	TreeElement(Object* element) {
		self(element, 0, 0);
	}

	TreeElement() {
		self(0, 0, 0);
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

	
	void setData(vector<Object*>* data) {
		if (data == 0) {
			this->data = new vector<Object*>();
		}
		else {
			this->data = data;
		}
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

