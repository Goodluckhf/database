#include <iostream>
#include "Student.h"
#include "Tree.h"

using namespace std;


class IndexBase {

};

class Index : public IndexBase{
private:

};


int main() {
	setlocale(LC_ALL, "Russian");
	Student* students = new Student("vasya", 1, 11.2);
	students->setId(1);
	
	Tree<int, Student>* primaryKeys = new Tree<int, Student>( [] (Student* student) -> int {
		return student->getId();
	});



	system("pause");
	return 0;
}