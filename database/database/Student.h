#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string lastName;
	float points;
	int group;
public:
	Student(string lastName, int group, float points);
	Student();
	string getName();
	float getPoints();
	int getGroup();
	void setName(string name);
	void setGroup(int group);
	void setPoints(float points);
	void show();
	static void edit(Student*, Student*);
};


