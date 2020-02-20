#include "student.h"
#include "degree.h"
#include <iostream>

//getters:
string Student::GetStudentID() const
{
	return string(studentID);
}
string Student::GetFirstName() const
{
	return string(firstName);
}
string Student::GetLastName() const
{
	return string(lastName);
}
string Student::GetEmail() const
{
	return string(studentEmail);
}
int Student::GetAge() const
{
	return studentAge;
}

int* Student::GetDaysToComplete()
{
	return daysToComplete;
};

Degree Student::GetDegree()
{
	return  studentDegree;
}

//setters:
void Student::SetStudentID(string idValue)
{
	studentID = idValue;
	return;
}

void Student::SetFirstName(string studentFirstName)
{
	firstName = studentFirstName;
	return;
}

void Student::SetLastName(string studentLastName)
{
	lastName = studentLastName;
	return;
}

void Student::SetEmail(string studEmail)
{
	studentEmail = studEmail;
	return;
}

void Student::SetAge(int age)
{
	studentAge = age;
	return;
}
void Student::SetDegree(Degree studDegree)
{
	studentDegree = studDegree;
}
void Student::SetDaysToComplete(int dayToComplete[4])
{
	int i = 0;
	for (i = 0; i < 4; ++i)
	{
		daysToComplete[i] = dayToComplete[i];
	}
	return;
}

void Student::print()
{
	cout << "	FirstName: " << GetFirstName();
	cout << "	Last Name: " << GetLastName();
	cout << "	Age: " << GetAge();
	cout << "	daysInCourse: ";
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		cout << daysToComplete[i] << " ";
	}
	cout << endl;
	if (studentDegree == 0)
	{
		cout << "SECURITY" << endl;
	}
	else if (studentDegree == 1)
	{
		cout << "NETWORKING" << endl;
	}
	else if (studentDegree == 2)
	{
		cout << "SOFTWARE" << endl;

	}
	
};

//constructors:
Student::Student()
{
	studentID = "ZZ";
	lastName = "xxx";
	firstName = "yyy";
	studentEmail = "xxx@yyy.zzz";
	studentAge = 99;
	for (int i = 0; i < 4; ++i)
	{
		daysToComplete[i] = i;
	}
	studentDegree = OTHER;


}
Student::Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int dayToComplete[], Degree studentDegree)
{
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmail(studentEmail);
	SetAge(studentAge);
	SetDaysToComplete(dayToComplete);
	SetDegree(studentDegree);
}
Degree Student::getDegreeProgram()
{
	return OTHER;
}
;

//destructor:
Student::~Student()
{

}