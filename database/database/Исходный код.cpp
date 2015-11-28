#include <iostream>
#include "Tree.h"
#include "Student.h"
using namespace std;





int main() {
	setlocale(LC_ALL, "Russian");
	Student* student = new Student("vasya", 1, 11.2);
	student->setId(1);
	Tree<int, Student>* primaryKeys = new Tree<int, Student>([] (Student* student) -> int{
		return student->getId();
	});



	system("pause");
	return 0;
}