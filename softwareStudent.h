#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H


#include "student.h"

class SoftwareStudent : public Student
{
	public:
		Degree getDegreeProgram();
		void print();
		SoftwareStudent();
		SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int dayToComplete[], Degree software);
		~SoftwareStudent();
		void test();
	private:
		Degree studentDegree = SOFTWARE;

};
#endif 