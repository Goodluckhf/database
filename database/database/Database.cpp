#include "Database.h"

Database::Database() {	



}

Database* Database::instance = 0;

Database* Database::getInstance() {
	if (Database::instance == 0) {
		Database::instance = new Database();
	}
	return Database::instance;
}

int Database::createIdIndex(Student* student) {
	return student->getId();
}

string Database::createNameIndex(Student* student) {
	return student->getName();
}

int Database::createGroupIndex(Student* student) {
	return student->getGroup();
}

float Database::createPointIndex(Student* student) {
	return student->getPoints();
}

bool Database::createTable(string name, vector<string> indexes) {
	for (int i = 0; i < indexes.size(); i++) {
		if (indexes[i] == "id") {

		}
	}
}
bool Database::createTable(string name) {

}
void Database::showTable() {

}
string Database::getTableName() {
	return this->tableName;
}