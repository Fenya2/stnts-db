#include <string>
#include <vector>

class Student
{
	public:
		static const int NAME_SIZE = 20;
		static const int SURNAME_SIZE = 20;
		static const int PATRONYMIC_SIZE = 20;
		static const int RECORD_FIELDS_QUANT = 5;
		Student();
		std::string name();
		std::string surname();
		std::string patronymic();
		int groupID();
		Student(std::string, std::string, std::string, int);
		Student(std::string);
		std::string toString();
	private:
		std::string _name;
		std::string _surname;
		std::string _patronymic;
		int _groupID;
};

class StudentsTable
{
	public:
		StudentsTable(std::string);
		int getstQnt();
		void create();
		void open();
		void add(Student);
		std::vector<Student> getAll();
		// bool isValid_***;
	private:
		int _curID;
		int _stQnt;
		std::string _path;
};
