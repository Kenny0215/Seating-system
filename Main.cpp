#include <iostream>
#include "Student.h"
using namespace std;

const int SIZE = 15;

int main()
{
	char program = 0, selection = 0;

	do
	{
		system("cls");

		Student students[] =
		{
			Student("Jack", 180.1),
			Student("Byran", 175.6),
			Student("Charles", 178.3),
			Student("Lucas", 168.4),
			Student("Merry", 163.5),
			Student("Caven", 172.8),
			Student("Lily", 165.7),
			Student("Olivia", 166),
			Student("Ivy", 170.2),
			Student("Elvis", 181.2),
			Student("Jane", 160.5),
			Student("Henry", 170.9),
			Student("James", 171.3),
			Student("Zoe", 164.9),
			Student("Gris", 168.5),
		};

		cout << "---------------------------------------";
		cout << "!!!!!Welcome to Bitwise Brotherhood!!!!!";
		cout << "------------------------------------" << endl;

		cout << endl;
		cout << "Please select a function\n1. Sorting\n2. Searching" << endl << ">> ";
		cin >> selection;
		cout << endl;

		if (selection == '1')
		{
			int orderChoice;

			cout << "This is the original list: \n";
			students[SIZE - 1].printStudent(students, SIZE);

			cout << "\nSelect sorting order:\n1. Ascending\n2. Descending\nEnter your choice (1 or 2): ";
			cin >> orderChoice;
			cout << endl;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
			}

			while (orderChoice != 1 && orderChoice != 2)
			{
				cout << "Invalid order selection, please try again." << endl;

				cout << "\nSelect sorting order:\n1. Ascending\n2. Descending\nEnter your choice (1 or 2): ";
				cin >> orderChoice;
				cout << endl;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
				}
			}

			students[SIZE - 1].sortByHeight(students, SIZE, orderChoice);

			if (orderChoice == 1)
			{
				cout << "This list is sorted in ascending order: " << endl;
			}
			else if (orderChoice == 2)
			{
				cout << "This list is sorted in descending order: " << endl;
			}

			students[SIZE - 1].printStudent(students, SIZE);

			cout << "\nThis is the seating chart:\n";
			students[SIZE - 1].displaySeating(students, SIZE, "");
		}
		else if (selection == '2')
		{
			string nameToSearch;
			bool found;
			Student foundStudent;

			cout << "This is the original list: \n";
			students[SIZE - 1].printStudent(students, SIZE);

			cout << "\nEnter the name of the student to search: ";
			cin >> nameToSearch;

			found = students[SIZE - 1].searchByName(students, SIZE, nameToSearch, foundStudent);

			if (found)
			{
				cout << "\nStudent found: " << foundStudent.name << ", Height: " << foundStudent.height << " cm" << endl
					<< "This student seat in the row " << foundStudent.foundRow + 1 << " column " << foundStudent.foundColumn + 1 << endl;
			}
			else
			{
				cout << "\nStudent " << nameToSearch << " not found." << endl;
			}
		}
		else
		{
			cout << "Invalid selection, please try again.\n";
		}

		cout << "\nDo you want to restart the program? (0 to stop)" << endl << ">> ";
		cin >> program;

	} while (program != '0');
}
