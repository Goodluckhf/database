#include "Database.h"

/*template<class T_return, class T_param>
bool Database<T_return, T_param>::createTable(string name) {
	this->tableName = name;
	return true;
}

template<class T_return, class T_param>
T_return Database<T_return, T_param>::insert(T_param* object) {
	return this->indexTree->add(object);
}

template<class T_return, class T_param>
vector<T_param*>* Database<T_return, T_param>::select(T_return sort) {
	return this->indexTree->findByIndex(sort);
}

template<class T_return, class T_param>
bool Database<T_return, T_param>::update(T_return sort, T_param* object) {
	return this->indexTree->edit(sort, object);
}

template<class T_return, class T_param>
bool Database<T_return, T_param>::remove(T_return sort) {
	return this->indexTree->remove(sort);
}
*/
template<class T_return, class T_param>
void Database<T_return, T_param>::showTable() {

}

template<class T_return, class T_param>
string Database<T_return, T_param>::getTableName() {
	return this->tableName;
}