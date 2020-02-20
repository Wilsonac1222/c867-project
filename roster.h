#pragma once

#ifndef ROSTER_H
#define ROSTER_H
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

#include <iostream>
#include <string>

using namespace std;

class Roster
{
public:
	void add(string studentDataRow);
	void remove(string studentID);
	void printAll();
	Student* getStudent(int v);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	int GetLastIndex();
	~Roster();
	Roster();
	
private:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr }; //pointer array for roster
	int totalCount;
	int lastIndex = -1;

};
#endif