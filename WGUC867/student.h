#pragma once
//Including the <string> and namespace to use string data types. Also included the "degree.h" file to reference the DegreeProgram enum.
#include <string>
#include "degree.h"
using namespace std;

//The student class.
class Student {
private: //These are private variables not accessible outside this class.
		string studentID;	string firstName; 	string lastName; 	string emailAddress; 	int age; 	int daysInCourse[3]; //array for 3 total courses.
	DegreeProgram degreeprogram;

public: //Includes functions that will reference the variables in the private section.
	
	//Getters for each attribute field to pull data for each variable.
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getArrayDaysInCourse();
	DegreeProgram getDegreeProgram();

	//Setters for each attribute field to assign new variable values.
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setArrayDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeprogram);

	//Empty constructor.
	Student(); 

	//Constructor with all variables/attributes included.
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram);
	
	//Added print() function to print specific student data.
	void print();

	//Added print() function to print specific student data.
	void printEmail();

	//Destructor to clear memory space.
	~Student();

};