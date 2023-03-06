#include "StudentDB.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

StudentsTable::StudentsTable(std::string path)
{
	_path = path;
	std::ifstream tblfile;
	tblfile.open(path);
	if(!tblfile.is_open())
		create();
	else 
	{
		tblfile.close();
		open();
	}
}

int StudentsTable::getstQnt()
{
	return _stQnt;
}

void StudentsTable::create()
{
	std::ofstream tblfile;
	tblfile.open(_path);
	tblfile.close();
	_curID = 0;
	_stQnt=0;
	return;
}

void StudentsTable::open()
{
	std::ifstream tblfile;
	tblfile.open(_path);
	std::string record;
	_stQnt = 0;
	while(std::getline(tblfile, record))
	{
		std::stringstream ss(record);
		ss >> _curID;
		_curID++;
		_stQnt++;
	}
	tblfile.close();
}

void StudentsTable::add(Student s)
{
	std::ofstream tblfile;
	tblfile.open(_path, std::ios::app);
	tblfile << _curID++ << ":" << s.toString() << std::endl;
	tblfile.close();
}

std::vector<Student> StudentsTable::getAll()
{
	std::ifstream tblfile;
	tblfile.open(_path);
	std::string record;
	std::vector<Student> students;
	Student* students2 = new Student[_stQnt];
	for(int i = 0; i < _stQnt; ++i)
	{
		getline(tblfile, record);
		students.push_back(Student(record));
	}
	return students;
}
