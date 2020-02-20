#include <iostream>
using namespace std;

#include "securityStudent.h"
#include "student.h"



SecurityStudent::SecurityStudent()
{
	studentID = "a1";
	firstName = "XXX";
	lastName = "YYY";
	studentEmail = "XXX@YYY.ZZZ";
	studentAge = 99;
	for (int i = 0; i < 4; ++i)
	{
		daysToComplete[i] = i;
	}
	studentDegree = SECURITY;
}

void SecurityStudent::print()
{
	{
		cout << "\t FirstName: " << GetFirstName();
		cout << "\t Last Name: " << GetLastName();
		cout << "\t Age: " << GetAge();
		cout << "\t daysInCourse: { ";
		int i = 0;
		for (i = 0; i < 2; ++i)
		{
			cout << daysToComplete[i] << ", ";
		}
		cout << daysToComplete[2]<< " } ";
		cout << "SECURITY" << endl;
	};
}

Degree SecurityStudent::getDegreeProgram()
{
	return SecurityStudent::studentDegree;
}
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int dayToComplete[], Degree SECURITY)
{
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmail(emailAddress);
	SetAge(age);
	SetDaysToComplete(dayToComplete);
	SetDegree(SECURITY);
}
;

SecurityStudent::~SecurityStudent()
{

}


