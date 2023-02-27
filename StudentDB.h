#include <string>

class Student
{
	public:
		Student();
		Student(std::string, std::string, std::string, int);
		std::string toString();
	private:
		std::string name;
		std::string surname;
		std::string patronymic;
		int group_id;
};

class StudentsTable
{
	public:
		StudentTable(std::string);
		void add(Student);
		Student* get(int);
		Student* getall();
	private:
		int curID;
		int numOfStudents;
};
