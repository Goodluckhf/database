#include "Student.h"


Student::Student( string lastName, int group, float points) {
	this->lastName = lastName;
	this->group = group;
	this->points = points;
}
Student::Student() {
	Student("", 0, 0);
}

string Student::getName() {
	return this->lastName;
}
float Student::getPoints() {
	return this->points;
}
int Student::getGroup() {
	return this->group;
}

void Student::setName(string name) {
	this->lastName = name;
}

void Student::setGroup(int group) {
	this->group = group;
}

void Student::setPoints(float points) {
	this->points = points;
}

void Student::show() {
	cout << "���: " << this->lastName << endl;
	cout << "������: " << this->group << endl;
	cout << "�����: " << this->points << endl;
}

void Student::edit(Student* stud, Student* newFields) {
	stud->setGroup(newFields->getGroup());
	stud->setPoints(newFields->getPoints());
	stud->setName(newFields->getName());
}