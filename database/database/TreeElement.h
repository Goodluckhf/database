#pragma once
#include <list>

using namespace std;

template <class Sort, class Object>
class TreeElement {
private:
	TreeElement<Sort, Object>* leftChild;
	TreeElement<Sort, Object>* rightChild;
	list<Object>* dataList;

public:
	TreeElement(Object*, TreeElement<Sort, Object>*, TreeElement<Sort, Object>*);
	TreeElement(Object*);
	TreeElement();
	Object* getData();
	TreeElement<Sort, Object>* getLeftChild();
	TreeElement<Sort, Object>* getRightChild();
	void setData(Object* data);
	void setLeftChild(TreeElement<Sort, Object>* child);
	void setRightChild(TreeElement<Sort, Object>* child);
	bool hasLeft();
	bool hasRight();
};

