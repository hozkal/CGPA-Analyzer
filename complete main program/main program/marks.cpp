#include "marks.h"

void marks::input()
	{
		int x;
		
		cout<<"Please enter which semester do you want to input the data to:";
			cin>>x;
			cout<<endl;
			do
			{
			if(x!=1)
			{
				cout<<"Do you want to manually inserted information for every subject GPA starting from semester 1(Y/y) or do you want to insert the current CGPA with the previous semesters CGPA(previous CGPA means the total of Grade Pointer Average of previous sems summarized to one number)(N/n):?";
				char choose;
				cin>>choose;
				do
				{
				
				if(choose=='y' || choose=='Y')
				{
					cgpa=0;
					for(int i=0;i<current_sem;i++)
					{
						cout<<"\nPlease enter gpa for all subjects for semester "<<i+1<<endl;
						cgpa=(cgpa+cg[i].subj_input())/2;
					}
					cout<<"Your cgpa is "<<cgpa<<endl;
					evaluate(cgpa);
					getCGPA(cgpa);
					return;}
				else if(choose=='n' || choose=='N')
				{
					cgpa=0;
					cout<<"\n\nPlease enter you previous semesters' Cumulative Grade Pointer Average (CGPA):";
					cin>>prev_cgpa;
					cout<<"\n";
					float fi=cg[0].subj_input();
					cgpa=(prev_cgpa+fi)/2;
					cout<<"Your cgpa is "<<cgpa<<endl;
					evaluate(cgpa);
					getCGPA(cgpa);
					return;
				}
				else
					cout<<"Please try again"<<endl;
				
				}while(choose!='Y' || choose!='y' || choose!='N' || choose!='n' );

			}
			else
			{
				cgpa=0;
				for(int i=0;i<current_sem;i++)
					{
						cout<<"\nPlease enter gpa for all subjects for semester "<<i+1<<endl;
						cgpa=(cgpa+cg[i].subj_input());
					}
				cout<<"Your cgpa is "<<cgpa<<endl;
				evaluate(cgpa);
				getCGPA(cgpa);
			}
			x++;
			}while (x < current_sem + 1);

	}
	void marks::inputfile(ostream& output)
	{
		int x;
		
		cout<<"Please enter which semester do you want to input the data to:";
			cin>>x;
			cout<<endl;
			do
			{
			if(x!=1)
			{
				cout<<"Do you want to manually inserted information for every subject GPA starting from semester 1(Y/y) or do you want to insert the current CGPA with the previous semesters CGPA(previous CGPA means the total of Grade Pointer Average of previous sems summarized to one number)(N/n):?";
				char choose;
				cin>>choose;
				do
				{
				
				if(choose=='y' || choose=='Y')
				{
					cgpa=0;
					for(int i=0;i<current_sem;i++)
					{
						cout<<"\nPlease enter gpa for all subjects for semester "<<i+1<<endl;
						cgpa=(cgpa+cg[i].subj_input())/2;
					}
					output<<this->cgpa<<":\n";
					cout<<"Your cgpa is "<<cgpa<<endl;
					evaluate(cgpa);
					getCGPA(cgpa);
					return;}
				else if(choose=='n' || choose=='N')
				{
					cgpa=0;
					cout<<"\n\nPlease enter you previous semesters' Cumulative Grade Pointer Average (CGPA):";
					cin>>prev_cgpa;
					cout<<"\n";
					float fi=cg[0].subj_input();
					cgpa=(prev_cgpa+fi)/2;
					output<<this->cgpa<<":\n";
					cout<<"Your cgpa is "<<cgpa<<endl;
					evaluate(cgpa);
					getCGPA(cgpa);
					return;
				}
				else
					cout<<"Please try again"<<endl;
				
				}while(choose!='Y' || choose!='y' || choose!='N' || choose!='n' );

			}
			else
			{
				cgpa=0;
				for(int i=0;i<current_sem;i++)
					{
						cout<<"\nPlease enter gpa for all subjects for semester "<<i+1<<endl;
						cgpa=(cgpa+cg[i].subj_input());
					}
				output<<this->cgpa<<":\n";
				cout<<"Your cgpa is "<<cgpa<<endl;
				evaluate(cgpa);
				getCGPA(cgpa);
			}
			x++;
			}while (x < current_sem + 1);

	}
	void marks::output()
	{
		putdata();
		
	}