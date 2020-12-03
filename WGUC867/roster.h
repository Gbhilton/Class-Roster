#pragma once
//Including the <string> and namespace to use string data types. Also included the "degree.h" file to reference the DegreeProgram enum.
#include <string>
#include "student.h"
using namespace std;

class Roster {
public:

	//Created an array of pointers to store the data provided in the studentData table for all 5 students.
	Student** classRosterArray; //Note: I can add ** and remove [] to create a dynamic array, not limited to 5.

	//Create a variable to store the last index spot in the array.
	int lastIndex;
	int size;

public:

	//Created an empty constructor.
	Roster();

	//Created a sized constructor for 5 possible students.
	Roster(int size);

	//Locate a student (get) in the classRosterArray based on it's index within the array.
	Student* getStudent(int index);

	//Creating a student object after parsing the string, then adding each student object to the classRosterArray object.
	void parseStudents(string studentList);

	//Adds a student to the roster/updates the roster object.
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeprogram);

	//Removes a student from the roster. If the ID does not exist, it gives an error message.
	bool remove(string studentID);

	//Print all function that loops through the print function found in student.cpp, and print each student's information.
	void printAll();

	//Prints the averages of all 3 days in course values, giving an average time to course completion for the student.
	void printAverageDaysInCourse(string studentID);

	//Verfiies if an email address is correct, and displays incorrect email address to the console. Valid contains ('@', ".") and not spaces.
	void printInvalidEmails();

	//Prints out student information for a degree program specified by the enumerated degree program type.
	void printByDegreeProgram(DegreeProgram degreeprogram);

	//Destructor
	~Roster();
};