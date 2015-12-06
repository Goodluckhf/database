#include <iostream>
#include "Student.h"
#include <string>
#include "Database.h"
using namespace std;





int main() {
	setlocale(LC_ALL, "Russian");
	Database<int, Student>* students = new Database<int, Student>([] (Student* stud) -> int{
		return stud->getGroup();
	});

	students->createTable("students");

	students->insert(new Student("Jenya", 7, 3.2));
	students->insert(new Student("Vasya", 3, 3.2));
	students->insert(new Student("Nikita", 10, 11.2));
	students->insert(new Student("Vasya", 1, 2.2));
	students->insert(new Student("Vasya", 1, 112.2));
	students->insert(new Student("Vasya", 10, 4.2));

	vector<Student*>* dbResult = students->select(7);
	
	for (int i = 0; i < dbResult->size(); i++) {
		dbResult->at(i)->show();
	}
	cout << endl << endl;
	students->update(7, new Student("lolka", 8, 5.1));
	dbResult = students->select(8);
	for (int i = 0; i < dbResult->size(); i++) {
		dbResult->at(i)->show();
	}
	cout <<"��������: "<< dbResult->size() << endl;
	cout << endl << endl;
	/*students->insert(new Student("Jenya", 7, 3.2));
	dbResult = students->select(7);

	for (int i = 0; i < dbResult->size(); i++) {
		dbResult->at(i)->show();
	}*/
	system("pause");
	return 0;
}