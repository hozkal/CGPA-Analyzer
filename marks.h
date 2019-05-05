#include <iostream>
#include <string>
#include <fstream>
#include "calculatecgpa.h"
#include "student.h"
using namespace std;

#ifndef MARKS_H
#define MARKS_H

class marks: public student ,public calculateCGPA
{
	float* gpa;
	float prev_cgpa,cgpa;
	int per;
	calculateCGPA cg[10];
	public: 
	void input();
	void inputfile(ostream& output);
	void output();
};

#endif