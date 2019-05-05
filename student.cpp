#include "student.h"

student::student()
	{
		
	}
void student::getdata()
	{
		cout<<"\n Enter the student matric id:";
		cin.ignore(10000,'\n');
		getline(cin,matric);
		cout<<"\n Enter the student name:";
		getline(cin,name);
		//cin.ignore(10000,'\n');
		cout<<"\n Enter the student address:";
		getline(cin,addr);
		//cin.ignore(10000,'\n');
		cout<<"\n Enter the student course:";
		getline(cin,course);
		//cin.ignore(10000,'\n');
		cout<<"\n Enter the current semester for the student:";
		cin>>current_sem;
	}
	void student::intofile(ofstream &output)
	{
		output<<this->matric<<":";
		output<<this->name<<":";
		output<<this->addr<<":";
		output<<this->course<<":";
		output<<this->current_sem<<":";
	}
	void student::intoNewfile(ofstream &output)
	{
		output<<this->matric<<":";
		output<<this->name<<":";
		output<<this->addr<<":";
		output<<this->course<<":";
		output<<this->current_sem<<":";
		output<<this->cg<<":\n";
	}
	void student::outfromfile(string a,string b,string c,string d,int u,float f)
	{
		matric=a;
		name=b;
		addr=c;
		course=d;
		current_sem=u;
		cg=f;
	}

	void student::putdata()
	{
		cout<<"\n the student matric id:"<<this->matric;
		cout<<"\n the student name:"<<this->name;
		cout<<"\n the student course:"<<this->course;
		cout<<"\nthe student address:"<<this->addr;
		cout<<"\nthe student's current semester:"<<this->current_sem;
		cout<<"\nthe student's current CGPA:"<<this->cg;
	}
	bool student::search(string s)
	{
		if (matric==s)
			return true;
		else 
			return false;
	}
	void student::getCGPA(float c)
	{
		cg=c;
	}