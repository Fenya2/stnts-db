#include <iostream>
#include <vector>
#include "StudentDB.h"

int main()
{
	StudentsTable st = StudentsTable("testtbl.txt");
	Student s1 = Student("Pupkin1", "Vasiliy", "Sergeevich",  100);
	Student s2 = Student("Pupkin2", "Vasiliy", "Sergeevich",  100);
	Student s3 = Student("Pupkin3", "Vasiliy", "Sergeevich",  100);
	Student s4 = Student("Pupkin4", "Vasiliy", "Sergeevich",  100);
	st.add(s1);
	st.add(s2);
	st.add(s3);
	st.add(s4);
	std::vector<Student> students = st.getAll();
	for(int i = 0; i < students.size(); ++i)
	{
		std::cout << students[i].toString() << std::endl;
	}
}
