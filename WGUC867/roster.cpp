//Include the roster.h class file to reference the class/functions and create them below. Include iostream for cout and string.
#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

//Create the empty Roster object and classRosterArray with new objects (blank for now) inside.
Roster::Roster() {
	this->lastIndex = -1;
	this->size = 0;
	this->classRosterArray = nullptr;
}

//Create the Roster object and classRosterArray with 5 new objects inside.
Roster::Roster(int size) {
	this->lastIndex = -1;
	this->size = size;
	this->classRosterArray = new Student*[size];
}

//Locate a student in the Roster::classRosterArray at a given index.
Student * Roster::getStudent(int index) {
	return classRosterArray[index];
}

/*Parse the student data from studentData table, then add the data to the student object, and add each completed student to the classRosterArray.
This will call the add() function below.*/
void Roster::parseStudents(string studentList) {
	if (lastIndex < 5) {
		lastIndex++;
		DegreeProgram degreeprogram;
		//Parse the strings by comma delimiting. Find each comma and extract the substring between each one, and place them in variables.
		//ID extraction.
		int commaLocation = studentList.find(",");
		string extractID = studentList.substr(0, commaLocation);

		//FirstName extraction.
		int commaLocationInc = commaLocation + 1;
		commaLocation = studentList.find(",", commaLocationInc);
		string extractFirstName = studentList.substr(commaLocationInc, commaLocation - commaLocationInc);

		//LastName extraction.
		commaLocationInc = commaLocation + 1;
		commaLocation = studentList.find(",", commaLocationInc);
		string extractLastName = studentList.substr(commaLocationInc, commaLocation - commaLocationInc);

		//Email address extraction.
		commaLocationInc = commaLocation + 1;
		commaLocation = studentList.find(",", commaLocationInc);
		string extractEmailAddress = studentList.substr(commaLocationInc, commaLocation - commaLocationInc);

		//Age extraction.
		commaLocationInc = commaLocation + 1;
		commaLocation = studentList.find(",", commaLocationInc);
		int extractAge = stoi(studentList.substr(commaLocationInc, commaLocation - commaLocationInc));

		//Course completion time extraction. Pull 3 out for each course time in days.
		commaLocationInc = commaLocation + 1;
		commaLocation = studentList.find(",", commaLocationInc);
		int extractDaysInCourse1 = stoi(studentList.substr(commaLocationInc, commaLocation - commaLocationInc)); //first course

		commaLocationInc = commaLocation + 1;
		commaLocation = studentList.find(",", commaLocationInc);
		int extractDaysInCourse2 = stoi(studentList.substr(commaLocationInc, commaLocation - commaLocationInc)); //second course

		commaLocationInc = commaLocation + 1;
		commaLocation = studentList.find(",", commaLocationInc);
		int extractDaysInCourse3 = stoi(studentList.substr(commaLocationInc, commaLocation - commaLocationInc)); //third course

		/*Degree program extraction. After extracting the string, I needed to change the datatype to my enum DegreeProgram. I used an if/elseif/else
		statement to perform this conversion. */
		commaLocationInc = commaLocation + 1;
		commaLocation = studentList.find(",", commaLocationInc);
		string extractDegreeProgram = studentList.substr(commaLocationInc, commaLocation - commaLocationInc);
		if (extractDegreeProgram == "SOFTWARE") degreeprogram = SOFTWARE;
		else if (extractDegreeProgram == "SECURITY") degreeprogram = SECURITY;
		else degreeprogram = NETWORK;

		//Call the add() function to add all the variables to the student object.
		add(extractID, extractFirstName, extractLastName, extractEmailAddress, extractAge, extractDaysInCourse1, extractDaysInCourse2,
			extractDaysInCourse3, degreeprogram);
	}
}

//The function to add each student to a student object. Then add that object to the classRosterArray at the given index.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeprogram) {
	//First make an array to get all the course (the 3 in the studentData tabel) into one array.
	int daysInCourse[3];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
}
//Loops through the roster object, and looks for a student based on the studentID parameter. If it finds it, it removes it from the roster.
bool Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (found == true) {
		cout << "Student found and removed from the roster." << endl;
	} else {
		cout << "Student does not currently exist" << endl;
		   }
	return found;
}

//Prints all the students information to the console. Calls the print() function from the Student class, printing each student one by one.
void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++) {
		this->classRosterArray[i]->print();
	}
}

//Loops through the classRosterArray based on studentID, then performed an average of the 3 days for course completion and displays to console.
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			int* avgDays = classRosterArray[i]->getArrayDaysInCourse();
			cout << "The average days in course for student ID of " << studentID << " is " << 
				double((avgDays[0] + avgDays[1] + avgDays[2]) / 3) << "." << endl;
		}
	}
}

/*Loops through the classRosterArray looking for invalid email addresses. If it finds invalid emails it prints them to the console. An invalid
email address will contain a space, or be missing '@' or a '.'.*/
void Roster::printInvalidEmails() {
	for (int i = 0; i <= lastIndex; i++) {
		int periodLocation = this->classRosterArray[i]->getEmailAddress().find('.');
		int atLocation = this->classRosterArray[i]->getEmailAddress().find('@');
		int spaceLocation = this->classRosterArray[i]->getEmailAddress().find(' ');

		if (periodLocation == std::string::npos) {
			this->classRosterArray[i]->printEmail();
		}
		if (atLocation == std::string::npos) {
			this->classRosterArray[i]->printEmail();
		}
		if (spaceLocation != std::string::npos) {
			this->classRosterArray[i]->printEmail();
		}
	}
}

//Loops through the classRosterArray looking for a given degreeprogram parameter, if found it prints that students information to the console.
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	cout << "Below are the students information that are currently enrolled in the Software degree program." << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeprogram) this->classRosterArray[i]->print();
	}
}

//Destructor.
Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
			delete this->classRosterArray[i];
		}
	cout << "Memory allocated for Roster released." << endl;
}
