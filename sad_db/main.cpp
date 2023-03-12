#include <string>
#include "Table.hpp"
#include <iostream>

struct Student
{
public:
	double rate;
};


int main()
{
	Table<Student> t;
	try
	{
		t.open("./tables/test.table");
	}
	catch(const char* msg)
	{
		std::cout << msg << std::endl;
	}
	std::cout << "ID: " << t.getCurID() << " QNT: " << t.getEntryQNT() << std::endl;
	t.insert(Student());
	std::cout << "ID: " << t.getCurID() << " QNT: " << t.getEntryQNT() << std::endl;
	t.close();
}
