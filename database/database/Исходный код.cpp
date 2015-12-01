#include <iostream>
#include "Student.h"
#include <string>
#include "Database.h"
using namespace std;





int main() {
	setlocale(LC_ALL, "Russian");
	//Student* student = new Student("vasya", 1, 11.2);
	Database<int, Student>* students = new Database<int, Student>([] (Student* stud) -> int{
		return stud->getGroup();
	});

	students->createTable("students");

	students->insert(new Student("Vasya", 1, 112.2));
	students->insert(new Student("Nikita", 10, 11.2));
	students->insert(new Student("Vasya", 1, 2.2));
	students->insert(new Student("Vasya", 3, 3.2));
	students->insert(new Student("Vasya", 10, 4.2));

	//vector<Student*>* dbResult = students->select(10);
	
	//for (int i = 0; i < dbResult->size(); i++) {
	//	dbResult->at(i)->show();
	//}

	/*Tree<int, Student>* primaryKeys = new Tree<int, Student>( [] (Student* student) -> int {
		return student->getId();
	});

	map<string, Any(*)(Student*)> callbacks =  map<string, Any(*)(Student*)>();
	callbacks.insert(make_pair("first", [] (Student* student) -> Any {		
		return Any(student->getGroup());
	}));
	cout<<callbacks["first"](students).cast<int>()<<endl;*/

	//cout << b.cast<string>() << endl;
	system("pause");
	return 0;
}