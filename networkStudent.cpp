using namespace std;
#include <iostream>
using namespace std;
#include "networkStudent.h"
#include "student.h"


NetworkStudent::NetworkStudent()
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
	studentDegree = NETWORKING;
}

Degree NetworkStudent::getDegreeProgram()
{
	return NetworkStudent::studentDegree;
}
void NetworkStudent::print()
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
		cout << "NETWORKING" << endl;
	};
}
NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int dayToComplete[], Degree Network)
{
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmail(emailAddress);
	SetAge(age);
	SetDaysToComplete(dayToComplete);
	SetDegree(Network);
}
;

NetworkStudent::~NetworkStudent()
{

}


