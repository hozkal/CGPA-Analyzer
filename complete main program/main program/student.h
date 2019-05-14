#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H
class student{

	string matric;
	string name;
	string addr;
	float cg;
	string course;
public:
	int current_sem;
	student();
	void getdata();
	void intofile(ofstream &output);
	void intoNewfile(ofstream &output);
	void outfromfile(string a,string b,string c,string d,int u,float f);
	void putdata();
	bool search(string s);
	void getCGPA(float c);
};
#endif