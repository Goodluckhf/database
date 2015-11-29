#pragma once
#include <iostream>
#include <map>
#include "Student.h"
#include <vector>
using namespace std;

class Database {
private:
	Database();
	static Database* instance;
	int createIdIndex(Student*);
	string createNameIndex(Student*);
	int createGroupIndex(Student*);
	float createPointIndex(Student*);
	string tableName;
public:
	static Database* getInstance();
	bool createTable(string, vector<string>);
	bool createTable(string);
	void showTable();
	string getTableName();


};

