#pragma once
#include <iostream>
using namespace std;

class Student {
private:
	int id;
	string lastName;
	float points;
	int group;
public:
	Student(int id, string lastName, int group, float points);
	Student();
	Student(string lastName, int group, float points);
	int getId();
	string getName();
	float getPoints();
	int getGroup();
	void setName(string name);
	void setId(int id);
	void setGroup(int group);
	void setPoints(float points);
	static void edit(Student*, Student*);
};


