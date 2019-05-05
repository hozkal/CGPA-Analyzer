#include "calculatecgpa.h"

float calculateCGPA::subj_input()
	{
		float tot=0;
		int data=0;
		float markS;
		GPA=new float[10];
		point=new float[10];
		credit=new int [10];
		int total_credit=0;
		
		while(data!=1 && data!=2)
		{
		cout<<"Do you want to enter the data of each subject \nby [1]marks(0-100) \n[2]by GPA (0.00-4.00)\nEnter 1 or 2:";
		cin>>data;
		system("CLS");
		if(data==1)
		{
		cout<<"\nHow many subjects does this student take this semester?:";
		cin>>sub;
		for(int i=0;i<sub;i++)
		{
			cout<<"\nPlease enter the current marks and credits for subject "<<i+1<<" (Input example:93.5 3):";
			cin>>markS>>credit[i];
			if(markS>=80)
				point[i]=4;
			else if(markS>=75)
				point[i]=3.67;
			else if(markS>=70)
				point[i]=3.33;
			else if(markS>=65)
				point[i]=3.00;
			else if(markS>=60)
				point[i]=2.67;
			else if(markS>=55)
				point[i]=2.33;
			else if(markS>=50)
				point[i]=2.00;
			else if(markS>=45)
				point[i]=1.67;
			else if(markS>=40)
				point[i]=1.33;
			else if(markS>=35)
				point[i]=1.00;
			else if(markS>=30)
				point[i]=0.67;
			else if(markS>=0)
				point[i]=0;
			tot=tot+(point[i]*credit[i]);
			total_credit=total_credit+credit[i];
		}
		}
		else if(data==2){
		cout<<"\nHow many subjects does this student take this semester?:";
		cin>>sub;
		for(int i=0;i<sub;i++)
		{
			cout<<"\nPlease enter the current GPA(Grade Pointer Average) and credits for subject "<<i+1<<" (Input example:3.2 3):";
			cin>>GPA[i]>>credit[i];
			tot=tot+(GPA[i]*credit[i]);
			total_credit=total_credit+credit[i];
		}
		}
		}
		delete [] GPA;
		delete [] credit;
		delete [] point;
		return tot/total_credit;}
	
	char calculateCGPA::evaluate(float c)
	{
		if(c==4.0)
		{
			cout<<"Congratulations!! You got the perfect CGPA and now among the special ones in Dean's list.Your grade is A!"<<endl;
			return 'A';
		}
		else if(c>=3.67)
		{
			cout<<"Congratulations!!You got an excellent CGPA and now among the special ones in Dean's list"<<endl;
			return 'A';
		}
		else if(c>=3.00)
		{
			cout<<"Congratulations!! You got a good CGPA .Your grade is B!"<<endl;
			return 'B';
		}
		else if(c>=2.00)
		{
			cout<<"You shall pass.You got a passing CGPA.Your grade is C!"<<endl;
			return 'C';
		}
		else
		{
			cout<<"Sadly you just fail.You got a failing CGPA.Your grade is D!"<<endl;
			return 'D';
		}
	}