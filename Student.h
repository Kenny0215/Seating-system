#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student
{
public:
	string name;
	double height;
	int foundRow;
	int foundColumn;

	Student();
	Student(string NAME, double HEIGHT);
	void printStudent(Student array[], int size);
	void sortByHeight(Student array[], int size, int order);
	void displaySeating(Student array[], int size, string targetName);
	bool searchByName(Student array[], int size, string targetName, Student& LocWanted);
};

#endif
