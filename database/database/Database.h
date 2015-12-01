#pragma once
#include <iostream>
#include <map>
#include "Student.h"
#include <vector>
#include "Tree.h"
using namespace std;

template<class T_return, class T_param>
class Database {
private:
	Tree<T_return, T_param>* indexTree;
	string tableName;
public:
	Database(T_return(*indexGetter)(T_param*)) {
		this->indexTree = new Tree<T_return, T_param>(indexGetter);
	}
	bool createTable(string name) {
		this->tableName = name;
		return true;
	}

	T_return insert(T_param* object) {
		return this->indexTree->add(object);
	}
	vector<T_param*>* select(T_return sort) {
		return this->indexTree->findByIndex(sort);
	}
	bool update(T_return sort, T_param* object) {
		return this->indexTree->edit(sort, object);
	}
	bool remove(T_return sort) {
		return this->indexTree->remove(sort);
	}
	void showTable();
	string getTableName();


};

