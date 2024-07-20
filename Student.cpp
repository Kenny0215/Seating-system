#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;

Student::Student() {}

Student::Student(string NAME, double HEIGHT)
{
	name = NAME;
	height = HEIGHT;
}

void Student::printStudent(Student array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << left << setw(8) << array[i].name
			<< ", Height: " << setw(4) << fixed << setprecision(1) << array[i].height << " cm" << endl;
	}
}

// Bubble Sort
void Student::sortByHeight(Student array[], int size, int order)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (order == 1)
			{
				if (array[j].height > array[j + 1].height)
				{
					Student temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
			else
			{
				if (array[j].height < array[j + 1].height)
				{
					Student temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}
}

void Student::displaySeating(Student array[], int size, string targetName)
{
	short columns = 5; // Fixed number of columns
	short rows = (size + columns - 1) / columns;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)  // 5 columns per row
		{
			int index = (i * 5) + j;

			if (index < size && !array[index].name.empty())
			{
				cout << "[ " << setw(8) << array[index].name << ", " << array[index].height << " ] ";

				if (array[index].name == targetName)
				{
					array[index].foundRow = i;
					array[index].foundColumn = j;
				}
			}
			else
			{
				break;
			}
		}
		cout << endl;
	}


	return;
}

// Sequential Search
bool Student::searchByName(Student array[], int size, string targetName, Student& LocWanted)
{
	int index = 0;
	bool found = false;

	cout << "\nThis seating chart is sorted in ascending order:\n";
	sortByHeight(array, size, 1);

	displaySeating(array, size, targetName);

	while (index < size)
	{
		if (array[index].name != targetName)
		{
			index++;
		}
		else
		{
			found = true;
			LocWanted = array[index];
			break;
		}
	}

	return found;
}
