//Including the <iostream> and namespace to use cout, and string. Also included the "student.h" file to reference the Student class.
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//Empty constructor
Student::Student() {
	//Nothing here. Just empty constructor. The main constructor for student object is below.
}

//Full constructor with all attributes included for creating a student object.
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i]; //loop through the 3 values for array.
	this->degreeprogram = degreeprogram;
}

//Getters to retrieve specific information for an individual attribute in the student.h file.
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getArrayDaysInCourse() {
	return daysInCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return degreeprogram;
}

//Setters to add/remove/manipulate data in each object for class student.
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setArrayDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < 3; i++)
	this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeprogram) {
	this->degreeprogram = degreeprogram;
}

//Print function from the Student class to print all data about one given student to the console.
void Student::print() {
	string any = "Security";
	if (degreeprogram == NETWORK) {
		any = "Network";
	} 
	if (degreeprogram == SOFTWARE) {
		any = "Software";
	}
	cout << left << studentID << "	First Name: " << firstName << "	Last Name: " << lastName << "	Age: " << age
		<< "	\nDays In Course: {" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}	Degree Program: " 
		<< any << ".\n";
}

//Print function from the Student class to print only email address for one given student to the console.
void Student::printEmail() {
	cout << left << emailAddress << "\n";
}

//Destructor.
Student::~Student() {
	//Nothing here right now.
}