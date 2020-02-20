#include <iostream>
using namespace std;
#include "softwareStudent.h"
#include "student.h"


SoftwareStudent::SoftwareStudent()
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
	studentDegree = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}
void SoftwareStudent::print()
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
		cout << daysToComplete[2] << " } ";
		cout << "SOFTWARE" << endl;
	};
}
SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int dayToComplete[], Degree Software)
{
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmail(emailAddress);
	SetAge(age);
	SetDaysToComplete(dayToComplete);
	SetDegree(Software);
}
;

SoftwareStudent::~SoftwareStudent()
{

}




