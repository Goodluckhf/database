#include "Student.h"


Student::Student(int id, string lastName, int group, float points) {
	this->id = id;
	this->lastName = lastName;
	this->group = group;
	this->points = points;
}
Student::Student() {
	Student(0, "", 0, 0);
}
Student::Student(string lastName, int group, float points) {
	Student(0, lastName, group, points);
}
int Student::getId() {
	return this->id;
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

void Student::setId(int id) {
	this->id = id;
}

void Student::setGroup(int group) {
	this->group = group;
}

void Student::setPoints(float points) {
	this->points = points;
}

static void Student::edit(Student* stud, Student* newFields) {
	stud->setGroup(newFields->getGroup);
	stud->setPoints(newFields->getPoints);
	stud->setName(newFields->getName);
}