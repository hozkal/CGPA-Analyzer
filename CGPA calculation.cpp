#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX 1000
class CalCGPA
{
	private:
		float TotCGPA;
		float CurCGPA;
		float CurCPA;
		float SubCPA[8];
		char* name;
		char course;
		int intake;
		string matric;
		int ic;
		int cursem;
	public:
		CalCGPA()
		{
			TotCGPA=0;
			CurCGPA=0;
			CurCPA=0;
			SubCPA[8]=0;
			name=0;
			course=0;
			intake=0;
			ic=0;
			cursem=0;
			
			
		}
		CalCGPA(float TCG,float CCG,float CCP,float SCP[8],char* n, char c,int i,int aic,int cs,string mat)
		{
			TotCGPA=TCG;
			CurCGPA=CCG;
			CurCPA=CCP;
			SubCPA[8]=SCP[8];
			name=n;
			course=c;
			intake=i;
			ic=aic;
			cursem=cs;
			matric=mat;
				}	
		~CalCGPA()
		{
			delete[]name;
			
				}	
		getName(char* n)
		{
			name=n;
					}	
		getCourse(char c)					
		{course=c;}
		getIntake(int i)
		{intake=i;}
					
};
int main()
{
	CalCGPA sec08[MAX];
	int i=0;
	fstream infile("CGPADatabase.txt",ios::in);
	if (!infile.is_open())
	{
		cout<<"File cant be opened.Please try again."<<endl;
		return -1;
	}
	while(!inile.eof())
	{
		infile>>sec08[i].getName;
		infile>>sec08[i].getCourse;
		infile>>sec08[i].getIntake;
	}
	outfile.close();
	return 0;
}
