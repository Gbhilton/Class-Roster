//Main program area.
//Including the <iostream> and namespace to use cout.
#include <iostream>
#include <string>
//Including all source/header files to reference them in the main function.
#include "roster.h"

using namespace std;

int main() {

	//Create variable to store total students on the current roster.
	int totalStudents = 5;

	//Print out name of the course, programming language used, WGU ID, and my name to the console.
	cout << "Course Title: C867 Programming and Scripting Applications \nProgramming Language: C++ \nWGU ID: 001408644 \nStudent Name: Grant Hilton"
		<< endl;
	cout << "\n";

	//Create a Roster object and called it "classRoster"
	Roster * classRoster = new Roster(5);  

	//Add each student to the new classRosterArray object.
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Grant,Hilton,ghilto1@wgu.edu,30,14,7,7,SOFTWARE" };

	//For each line in the studentData table, it triggers the parseStudents() function from the roster class.
	for (int i = 0; i < totalStudents; i++) {
		classRoster->parseStudents(studentData[i]);
	}

	//State how many students were added.
	cout << "A total of " << totalStudents << " students were added to the roster." << endl;
	cout << "\n";

	//Print all student information to the console, one student at a time for all students.
	cout << "All information for the " << totalStudents << " students is provided below:" << endl;
	classRoster->printAll();
	cout << "\n";

	//Print to the console any emails that are invalid in the studentData table provided. Invalid e-mails contain a space, or missing '@' and '.'.
	cout << "The following email addresses are invalid:" << endl;
	classRoster->printInvalidEmails();
	cout << "\n";

	//loop through classRosterArray and for each element below:
	//Print to the console the average of all 3 daysInCourse values for each student, giving an average time of course completion for all students.
	for (int i = 0; i < totalStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getStudentID());
	}
	cout << "\n";

	//Print to the console all student's information that are currently in a degree program of "Software".
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << "\n";

	//Remove the students full information based on the given studentID.
	cout << "Removing students with ID: 'A3' from the roster." << endl;
	if (classRoster->remove("A3")) {
		totalStudents--;
	}
	cout << "\n";

	//Print all student information to the console, one student at a time for all students. (This will show that "A3" student ID is removed.)
	cout << "All information for the " << totalStudents << " students is provided below:" << endl;
	classRoster->printAll();
	cout << "\n";

	//Print to the console an error message because studentID "A3" will already have been removed.
	cout << "Removing students with ID: 'A3' from the roster." << endl;
	if (classRoster->remove("A3")) {
		totalStudents--;
	}
	cout << "\n";

	//Destructor is called to release all memory allocated to the Roster class. Thus ending the program.
	Roster();

	return 0;

}