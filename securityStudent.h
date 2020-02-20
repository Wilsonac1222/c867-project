#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"


class SecurityStudent : public Student
{
public:
	SecurityStudent();
	void print();
	Degree getDegreeProgram();
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], Degree SECURITY);
	~SecurityStudent();
	
private:
	Degree studentDegree = SECURITY;

};
#endif 