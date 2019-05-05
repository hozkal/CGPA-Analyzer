#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef CALCULATECGPA_H
#define CALCULATECGPA_H

class calculateCGPA
{
	int sub;
	float CGPA;
	float* point;
	float* GPA;
	int* credit;
public:
	float subj_input();
	char evaluate(float c);
};

#endif