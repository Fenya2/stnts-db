#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>

template <typename Entry> class Table
{
public:
	static const int MAX_NAME_SIZE = 20;
	Table();
	Table(std::string);
	std::string getPath();
	int getCurID();
	int getEntryQNT();
	void create(std::string);
	void open(std::string);
	void close();
	void insert(Entry);
	Entry get(int);
	void remove(int);
	void update(int, Entry);
private:
	const char _fileDef[7] = "sadTBL";
	char _name[MAX_NAME_SIZE];
	std::string _path;
	int _curID;
	int _entryQNT;
	const int PREFIX_SIZE = 7 + sizeof(_fileDef) + sizeof(int) + sizeof(int);
	void updatePrefix(const char*, int, int);
	void updatePrefix(int, int);
};

/*
tablefile structure:
PREFIX: "sad_db"(6)|name(20)|EntryQnt(4(int))|CurID(4(int))|
Entryes: ...
*/

template <typename Entry> Table<Entry>::Table(std::string path)
{
	FILE* tblfile;
	tblfile=fopen(path.c_str(), "r");
	if(!tblfile)
		create(path);
	else 
	{
		fclose(tblfile);
		open(path);
	}
}

template <typename Entry> Table<Entry>::Table()
{

}

template <typename Entry> std::string Table<Entry>::getPath()
{
	return _path;
}

template <typename Entry> int Table<Entry>::getCurID()
{
	return _curID;
}

template <typename Entry> int Table<Entry>::getEntryQNT()
{
	return _entryQNT;
}

// написать проверки, что все хорошо записалось.
template <typename Entry> void Table<Entry>::create(std::string path)
{
	_entryQNT = 0; 
	_curID = 0;
	char tableName[MAX_NAME_SIZE] = "test"; // здесь должна быть функция, которая вычленяет имя из пути(basename с убиранием расширения) (лучше сделать библиотеку для таких штук)
	FILE* tblfile;
	tblfile=fopen(path.c_str(), "wb");
	fwrite(_fileDef, sizeof(char), sizeof(_fileDef), tblfile);
	fwrite(tableName, sizeof(char), sizeof(tableName), tblfile);
	fwrite(&_entryQNT, sizeof(int), 1, tblfile);
	fwrite(&_curID, sizeof(int), 1, tblfile);
	fclose(tblfile);
	_path=path;
	return;
}
// написать проверки, что все хорошо записалось.
template <typename T> void Table<T>::open(std::string path)
{
	char sym;
	FILE* tblfile;
	tblfile=fopen(path.c_str(), "rb");
	for(int i = 0; i < 7; ++i)
	{
		fread(&sym, sizeof(char), 1, tblfile);
		if(_fileDef[i] != sym)
			throw "Entered file is not a table";
	}
	fread(&_name, sizeof(_name), 1, tblfile);
	fread(&_entryQNT, sizeof(int), 1, tblfile);
	fread(&_curID, sizeof(int), 1, tblfile);
	fclose(tblfile);
	_path=path;
	return;
}

template <typename T> void Table<T>::close()
{
	updatePrefix(_curID, _entryQNT);
}

template <typename Entry> void Table<Entry>::updatePrefix(int ID, int QNT) // то же самое
{
	FILE* tblfile;
	tblfile=fopen(_path.c_str(), "r+");
	if(!tblfile)
		throw "can't update prefix";
	fseek(tblfile, sizeof(_fileDef)+sizeof(_name), SEEK_SET);
	fwrite(&ID, sizeof(int), 1, tblfile);
	fwrite(&QNT, sizeof(int), 1, tblfile);
	fclose(tblfile);
	return;
}

template <typename Entry> void Table<Entry>::insert(Entry entry)
{
	_curID++;
	_entryQNT++;
}
