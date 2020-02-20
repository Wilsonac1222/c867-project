#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
using namespace std;

Roster::Roster() 
{
	this->totalCount = 0;
	this->lastIndex = -1;
	for (int i = 0; i < 5; ++i)
	{
		this->classRosterArray[i] = nullptr;
	}

}



int Roster::GetLastIndex()
{
	return lastIndex;
}

Roster::~Roster()
{
	cout << "roster is deleted" << endl;
	for (int i = 0; i < 5; ++i)
	{
		delete classRosterArray[i];
	}
	return;
}

void Roster::add(string studentDataRow)
{
	int rhs = studentDataRow.find(",");                                            //lines 36-72 parse through the string of student data using the comma deliminators 
	                 															   //to find variables for the student objects
	string sID = studentDataRow.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentDataRow.find(",", lhs);
	string firstName = studentDataRow.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentDataRow.find(",", lhs);
	string lastName = studentDataRow.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentDataRow.find(",", lhs);
	string emailAddress = studentDataRow.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentDataRow.find(",", lhs);
	int age = stoi(studentDataRow.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentDataRow.find(",", lhs);
	int courseDays1 = stoi(studentDataRow.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentDataRow.find(",", lhs);
	int courseDays2 = stoi(studentDataRow.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentDataRow.find(",", lhs);
	int courseDays3 = stoi(studentDataRow.substr(lhs, rhs - lhs));

	int howManyDays[] = { courseDays1, courseDays2, courseDays3 };

	lhs = rhs + 1;
	rhs = studentDataRow.find(",", lhs);
	string sDegree = studentDataRow.substr(lhs, rhs - lhs);
	
	
	if (sDegree == "SOFTWARE")
	{
		classRosterArray[lastIndex+1] = new SoftwareStudent(sID, firstName, lastName, emailAddress, age, howManyDays, SOFTWARE);
		++lastIndex;
	}
	else if(sDegree == "SECURITY")
	{
		classRosterArray[lastIndex+1] = new SecurityStudent(sID, firstName, lastName, emailAddress, age, howManyDays, SECURITY);
		++lastIndex;
	}
	else if (sDegree == "NETWORKING")
	{
		classRosterArray[lastIndex+1] = new NetworkStudent(sID, firstName, lastName, emailAddress, age, howManyDays, NETWORKING);
		++lastIndex;
	}
	return;
}

void Roster::remove(string studentID)
{
	int validID = 0;
	for (int i = 0; i < lastIndex; ++i)
	{
		if (classRosterArray[i] != nullptr)
		{
			if ((*classRosterArray[i]).GetStudentID() == studentID)
			{
				classRosterArray[i] = nullptr;
				++validID;
				cout << "Student " << studentID << " has been removed" << endl;
			};
		};
	};
	if (validID == 0)
	{
		cout << "No student matches ID: " << studentID << endl;
	};
	return;
}

Student* Roster::getStudent(int v)
{
	return classRosterArray[v];
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < lastIndex + 1; ++i)
	{
		if (((*this->getStudent(i)).GetStudentID()) == studentID)
		{
			double avgDays = 0.0;
			for (int j = 0; j < 3; ++j)
			{
				avgDays = avgDays + (((*classRosterArray[i]).GetDaysToComplete())[j]);
			}
			avgDays = avgDays / 3.0;
			cout << "Student# " << studentID << " averaged "<< avgDays << " days in their courses." << endl;
		};
	};
}
void Roster::printInvalidEmails()
{
	cout << "Invalid Student Emails: " << endl;
	for (int i = 0; i < lastIndex + 1; ++i)
	{
		if (classRosterArray[i] != nullptr)
		{
			string emailAddr = "none";
				emailAddr = ((*classRosterArray[i]).GetEmail());
				if (emailAddr.find('@') == string::npos)
				{
					cout <<"	"<< emailAddr << endl;
				};
				if (emailAddr.find('.') == string::npos)
				{
					cout <<"	"<< emailAddr << endl;
				}
				if (emailAddr.find(" ") != string::npos)
				{
					cout <<"	"<< emailAddr << endl;
				}
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	Degree tempDegree = OTHER;
	if (degreeProgram == 0)
	{
		tempDegree = SECURITY;
	}
	else if (degreeProgram == 1)
	{
		tempDegree = NETWORKING;
	}
	else if (degreeProgram == 2)
	{
		tempDegree = SOFTWARE;
	}
	cout << "Students in Degree Program: " << endl;
	for (int i = 0; i < lastIndex + 1; ++i)
	{
		if ((*this->getStudent(i)).getDegreeProgram() == tempDegree)
		{
		cout << (*this->getStudent(i)).GetLastName() << ", " << (*this->getStudent(i)).GetFirstName() << endl;
		};
	}
	cout << endl;
};
	


void Roster::printAll()
{
	cout << "DISPLAYING FULL ROSTER:" << endl;
	for (int i = 0; i < lastIndex+1; ++i)
	{
		(*this->getStudent(i)).print();
		cout << endl;
	}
}





int main()
{
	cout << "SCRIPTING AND PROGRAMMING APPLICATIONS : C867 (using c++) " << endl;
	cout << "WILSONAC STUDENT ID: #007" << endl << endl;

	const int studentCount = 5;
	std::string studentData[] = //array of data for all students
	{ 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORKING",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,WILSONAC,WILSONAC,GIT@HUB.COM,34,17,15,19,SOFTWARE" 
	};

	Roster ClassRoster;
	for (int i = 0; i < 5; ++i)  //populates roster with all 5 students
	{
		ClassRoster.add(studentData[i]);
	};

	ClassRoster.printAll();  //prints out all roster info
	ClassRoster.printInvalidEmails(); //verifies each email address and prints emails that are invalid
	
	for (int i = 0; i < 5; ++i)  //looping through each element to find each student's average days in class
	{
		ClassRoster.printAverageDaysInCourse((*ClassRoster.getStudent(i)).GetStudentID());
	}
	cout << endl;

	ClassRoster.printByDegreeProgram(SOFTWARE);  //prints all students in the Software program
	ClassRoster.remove("A3");  //removes the student 
	ClassRoster.remove("A3"); //yields no student record found
	
		
	return 0;
};
