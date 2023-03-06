#include "StudentDB.h"
#include <sstream>
#include <string>

Student::Student(std::string name, std::string surname, std::string patronymic, int groupID)
{
	if(name.size() > NAME_SIZE)
		throw "too long name.";
	if(surname.size() > SURNAME_SIZE)
		throw "too long surname.";
	if(name.size() > PATRONYMIC_SIZE)
		throw "too long patronymic.";
	_name = name;
	_surname = surname;
	_patronymic = patronymic;
	_groupID = groupID;
}

Student::Student(std::string tblRecord)
{
	std::string field;
	std::stringstream ss(tblRecord);
	std::getline(ss, field, ':');
	std::getline(ss, _name, ':');
	std::getline(ss, _surname, ':');
	std::getline(ss, _patronymic, ':');
	std::getline(ss, field, ':');
	_groupID = std::stoi(field);
}

std::string Student::name()
{
	return _name;
}

std::string Student::surname()
{
	return _surname;
}

std::string Student::patronymic()
{
	return _patronymic;
}

int Student::groupID()
{
	return _groupID;
}

std::string Student::toString()
{
	return _name + ":" + _surname + ":" + _patronymic + ":" + std::to_string(_groupID);
}
