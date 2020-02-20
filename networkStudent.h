#pragma once
#define NetworkStudent_H


#include "student.h"

class NetworkStudent : public Student
{
public:
	NetworkStudent();
	Degree getDegreeProgram();
	using Student::Student;
	void print();
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int dayToComplete[], Degree Network);
	~NetworkStudent();

private:
	Degree studentDegree = NETWORKING;

};

