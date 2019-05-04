#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <conio.h>
using namespace std;
class student 
{
	string matric;
	string name;
	string addr;
	string course;
	public: 
	int current_sem;
	student()
	{
		
	}
	void getdata()
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
	void intofile(ofstream &output)
	{
		output<<this->matric<<":";
		output<<this->name<<":";
		output<<this->addr<<":";
		output<<this->course<<":";
		output<<this->current_sem<<":\n";
	}
	void outfromfile(string a,string b,string c,string d,int u)
	{
		/*getline (input,matric,':');
		//cout<<matric<<"\n";
		getline (input,name,':');
		//cout<<name<<'\n';
		getline (input,addr,':');
		//cout<<addr<<'\n';
		getline (input,course,':');
		//cout<<city<<'\n';
		getline(input,to_string((long long)current_sem),'\n');
		//cout<<current_sem<<'\n';*/
		matric=a;
		name=b;
		addr=c;
		course=d;
		current_sem=u;
		
	}

	void putdata()
	{
		cout<<"\n the student matric id:"<<this->matric;
		cout<<"\n the student name:"<<this->name;
		cout<<"\n the student address:"<<this->addr;
		cout<<"\nthe student course:"<<this->course;
		cout<<"\nthe student's current semester:"<<this->current_sem;
	}
	bool search(string s)
	{
		if (matric==s)
			return true;
		else 
			return false;
	}
};
class calculateCGPA
{
	int sub;
	float CGPA;
	float* GPA;
	int* credit;
public:
	float subj_input()
	{
		float tot=0;
		GPA=new float[10];
		credit=new int [10];
		int total_credit=0;
		cout<<"\nHow many subjects does this student take this semester?:";
		cin>>sub;
		for(int i=0;i<sub;i++)
		{
			cout<<"\nPlease enter the current GPA(Grade Pointer Average) and credits for subject "<<i+1<<" (Input example:3.2 3):";
			cin>>GPA[i]>>credit[i];
			tot=tot+(GPA[i]*credit[i]);
			total_credit=total_credit+credit[i];
		}
		delete [] GPA;
		delete [] credit;
		return tot/total_credit;
	}
	char evaluate(float c)
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
};
class marks: public student ,public calculateCGPA
{
	float* gpa;
	float prev_cgpa,cgpa;
	int per;
	calculateCGPA cg[10];
	public: 
	void input()
	{
		int x;
		
		cout<<"Please enter which semester do you want to input the data to:";
			cin>>x;
			cout<<endl;
			do{
				if (x != 1)
				{
					cout << "Do you want to manually inserted information for every subject GPA starting from semester 1(Y/y) or do you want to insert the current CGPA with the previous semesters CGPA(previous CGPA means the total of Grade Pointer Average of previous sems summarized to one number)(N/n):?";
					char choose;
					cin >> choose;
					do
					{

						if (choose == 'y' || choose == 'Y')
						{
							cgpa = 0;
							for (int i = 0; i < current_sem; i++)
							{
								cout << "\nPlease enter gpa for all subjects for semester " << i + 1 << endl;
								cgpa = (cgpa + cg[i].subj_input()) / 2;
							}
							cout << cgpa << endl;
							evaluate(cgpa);
							return;
						}
						else if (choose == 'n' || choose == 'N')
						{
							cgpa = 0;
							cout << "\n\nPlease enter you previous semesters' Cumulative Grade Pointer Average (CGPA):";
							cin >> prev_cgpa;
							cout << "\n";
							float fi = cg[0].subj_input();
							cgpa = (prev_cgpa + fi) / 2;
							cout << cgpa << endl;
							evaluate(cgpa);
							return;
						}
						else
							cout << "Please try again" << endl;

					} while (choose != 'Y' || choose != 'y' || choose != 'N' || choose != 'n');

				}
				else
				{
					cgpa = 0;
					for (int i = 0; i < current_sem; i++)
					{
						cout << "\nPlease enter gpa for all subjects for semester " << i + 1 << endl;
						cgpa = (cgpa + cg[i].subj_input());
					}
					cout << cgpa;
					evaluate(cgpa);
				}
				x++;
			} while (x < current_sem + 1);
	}
	void output()
	{
		putdata();
		
	}
	
};
void mainDisplay()
{
	 int i, j, k = 0,n=10; 
    int py=n,px=n;
	int wave_height=5;
    int wave_length=10;
	 for(i=1;i<=wave_height;i++)
    {
    	cout<<"\t\t\t";
    	for(j=1;j<=wave_length;j++)
    	{
    		for(int l=1;l<=wave_height;l++)
    		{
    			if(i==l||i+l==wave_height+1)
    				cout<<">>";
    			else
    				cout<<" ";
			}
		}
		cout<<endl;
	}
    for (i = 1; i <= n; i++) 
    { 
    	cout<<"\t\t\t\t\t\t";
         
        for (j = i; j < n; j++) { 
            cout << " "; 
        } 
       
        while (k != (2 * i - 1)) { 
            if (k == 0 || k == 2 * i - 2) 
                cout << "#"; 
            else
                cout << " "; 
            k++; 
            ; 
        } 
        k = 0; 
        cout << endl; 
    } 
    cout<<"\t\t\t\t\t\t";
    for (i = 0; i < 2 * n - 1; i++) { 
        cout << "#"; 
    } 
    cout<<endl;
    for(int i=1;i<=n-2;i++)
	 {
	 	cout<<"\t\t\t\t\t\t";
	 	for(int j=1;j<n*2;j++)
	 	{
	 		if(j>px&&j<py)
	 			cout<<" ";
	 		else 
	 			cout<<"*";
	 	
		 }
		 	
		 px--;
		 py++;
		 
		 cout<<endl;
	 }
	 cout<<"\t\t\t\tPress\t\t**     CGPA \t **\tPress\n";
	 cout<<"\t\t\t\tany key\t\t*    Analyzer\t  *\tany key\n";
	 cout<<"\t\t\t\tto\t\t*       by   \t  *\tto\n";
	  cout<<"\t\t\t\tcontinue\t**    hozkal\t **\tcontinue\n";
	  for(int i=1;i<=n-2;i++)
	 {
	 	cout<<"\t\t\t\t\t\t";
	 	for(int j=1;j<n*2;j++)
	 	{
	 		if(j>px&&j<py)
	 			cout<<" ";
	 		else 
	 			cout<<"*";
	 	
		 }
		 	
		 px++;
		 py--;
		 
		 cout<<endl;
	 }
	 
	 for (i = 1; i <= n; i++) { 
        cout<<"\t\t\t\t\t\t";
        for (j = 1; j < i; j++) { 
            cout << " "; 
        } 
  
        for (j = 1; j <= (n * 2 - (2 * i - 1)); j++) { 
  
            if (i == 1 || j == 1 || j == (n * 2 - (2 * i - 1))) { 
                cout << "#"; 
            } else { 
                cout << " "; 
            } 
        } 
  
        cout << endl; 
    } 
	  for(i=1;i<=wave_height;i++)
    {
    	cout<<"\t\t\t";
    	for(j=1;j<=wave_length;j++)
    	{
    		for(int l=1;l<=wave_height;l++)
    		{
    			if(i==l||i+l==wave_height+1)
    				cout<<">>";
    			else
    				cout<<" ";
			}
		}
		cout<<endl;
	}
	 _getch();
	 system("CLS");
}
 
int main()
{
	mainDisplay();
	cout<<"\n\n\nEnter 'yes' if you want to create a file to save all your input data later or enter any other character if you dont want to:";
	string input;
	cin>>input;
	marks* m1;
	m1=new marks [100];
	int ch;
	int student_counter=0;
	if(input=="yes" || input == "YES")
	{
		for(int i=0;i<45;i++)
	{
		cout<<"//";
	}
	string filed,outfiled;
	cout<<"Please create your file (Any name):";
	cin.ignore(10000,'\n');
	getline(cin,filed);
	
	cout<<"\n";
	filed.append(".txt");
	ofstream makefile(filed);
	
	//makefile.close();
	//ifstream infile(filed);
	if (!makefile.is_open())
	{
		cout<<"File cant be opened.Please try again."<<endl;
		return -1;
	}
		
		do 
	{
		cout<<"\n\t\t\t\t\t=====================================";
		cout<<"\n\n\t\t\t\t\t1.Enter data";
		cout<<"\n\t\t\t\t\t2.Search for data";
		cout<<"\n\t\t\t\t\t3. File processor";
		cout<<"\n\t\t\t\t\t4.Back to the opening screen menu";
		cout<<"\n\t\t\t\t\t5.exit";
		cout<<"\n\t\t\t\t\t=====================================";
		cout<<"\n \t\t\t\t\tPlease enter your input accordingly:";
		cin>>ch;
		if (!(int)(ch)) {
			return 0;
		}
		else {}
		system("CLS");
		
			if(ch==1)
			{
			cout<<"\n\nPlease insert the number of students you wish to entered the information to:";
			int inf;
			cin >> inf;
			if (!(int)isdigit(inf)) {
				try {
					if ((inf <= 0))
						throw "Invalid !!!!";

				}
				catch (...) {
					int i = 0;

					cout << "Please try again with number??" << endl;
					break;
				}

			}
			else {
				try {
					if ((inf <= 0))
						throw "Invalid !!!!";

				}
				catch (...) {
					do {
						cout << "Please try again" << endl;
						cin >> inf;
						continue;
					} while ((inf <= 0));
				}
			}
			for(int i=0;i<inf;i++)
			{
			m1[i].getdata();
			m1[i].intofile(makefile);
			m1[i].input();
			}


			exit;
			}
			
 
			else if(ch==2)
			{
			cout<<"Please enter the matric id of the students you want to search:";
			string searching ("0");
			int temp=0;
			cin.ignore(10000,'\n');
			getline(cin, searching);
			for(int i=0;i<100;i++)
			{
				if (m1[i].search(searching) == 1)
				{
					cout << "found" << endl;
					temp = i;
					m1[temp].output();
					break;
				}
				else 
					cout << " " << endl;
				break;
			}
			exit;
			}
 
			else if(ch==3)
			{
			string line,comma_string;
			string a,b,c,d,temp[5];
			int e,etemp=0,i;
			int count=0;
			string delimiter=":";
			cout<<"Enter the name of your file :";
			cin>>outfiled;
			cin.ignore(10000,'\n');
			outfiled.append(".txt");
			ifstream gototheinput(outfiled);
			
			while (getline(gototheinput, line))
			{
				istringstream iss(line);
			
			if (!(iss >> a)) { cout<<"lol"<<endl;
				break; } // error
				//m1[i].outfromfile(a,b,c,d,e);
			i=0;
			size_t pos = 0;
			string token;
			while ((pos = line.find(delimiter)) != std::string::npos) 
			{
			 token = line.substr(0, pos);
			 temp[i]=token;
			line.erase(0, pos + delimiter.length());
			i++;
			}
			i=0;
			a=temp[0];
			b=temp[1];
			c=temp[2];
			d=temp[3];
			e=atoi(temp[4].c_str());
			m1[count].outfromfile(a,b,c,d,e);
				count++;
			}
			gototheinput.close();
			
			for(int i=0;i<count;i++)
			{
				m1[i].putdata();
			}
			
			exit;
			}
			else if(ch==4)
			{makefile.close();
				main();}
			else if (ch == 5)
			return 0;

	} while (ch!=5);
	
	}
	else
	{
	
	do 
	{
		cout<<"\n\t\t\t\t\t=====================================";
		cout<<"\n\n\t\t\t\t\t1.Enter data";
		cout<<"\n\t\t\t\t\t2.Search for data";
		cout<<"\n\t\t\t\t\t3. File processor";
		cout<<"\n\t\t\t\t\t4.Back to the opening screen menu";
		cout<<"\n\t\t\t\t\t5.exit";
		cout<<"\n\t\t\t\t\t=====================================";
		cout<<"\n \t\t\t\t\tPlease enter your input accordingly:";
		cin>>ch;
		if (!(int)(ch)) {
			return 0;
		}
		else {  }
		system("CLS");
			if(ch==1)
			{
			cout<<"\n\nPlease insert the number of students you wish to entered the information to:";
			int inf;
			cin >> inf;
			 if(!(int)isdigit(inf)){
				try {
					if ((inf <= 0))
						throw "Invalid !!!!";

				}
				catch (...) {
					int i=0;
					
						cout << "Please try again with number??" << endl;
						break;
				}
				
			}
			 else {
				 try {
					 if ((inf <= 0))
						 throw "Invalid !!!!";

				 }
				 catch (...) {
					 do {
						 cout << "Please try again" << endl;
						 cin >> inf;
						 continue;
					 } while ((inf <= 0));
				 }
			 }
			for(int i=0;i<inf;i++)
			{
			m1[i].getdata();
			m1[i].input();
			}
			exit;
			}
			
 
			else if(ch==2)
			{
			cout<<"Please enter the matric id of the students you want to search:";
			string searching ("0");
			int temp=0;
			cin.ignore(10000,'\n');
			getline(cin,searching);
			for(int i=0;i<100;i++)
			{
				if (m1[i].search(searching) == 1)
				{
					cout << "found" << endl;
					temp = i;
					m1[temp].output();
					break;
					
				}
				else cout << "not found" << endl;
				break;
			}
			exit;
			}
 
			else if(ch==3)
			{
			string line,comma_string,outfiled;
			string a,b,c,d,temp[5];
			int e,etemp=0,i;
			int count=0;
			string delimiter=":";
			cout<<"Enter the name of your file :";
			cin>>outfiled;
			cin.ignore(10000,'\n');
			outfiled.append(".txt");
			ifstream gototheinput(outfiled);
			
			while (getline(gototheinput, line))
			{
				istringstream iss(line);
			
			if (!(iss >> a)) { cout<<"lol"<<endl;
				break; } // error
			
			i=0;
			size_t pos = 0;
			string token;
			while ((pos = line.find(delimiter)) != string::npos) 
			{
			 token = line.substr(0, pos);
			 temp[i]=token;
			line.erase(0, pos + delimiter.length());
			i++;
			}
			i=0;
			a=temp[0];
			b=temp[1];
			c=temp[2];
			d=temp[3];
			e=atoi(temp[4].c_str());
			
			m1[count].outfromfile(a,b,c,d,e);
				count++;
			}
			gototheinput.close();
			
			for(int i=0;i<count;i++)
			{
				m1[i].putdata();
			}
			
			exit;
			}
			else if(ch==4)
				main();
			else if(ch == 5)
			return 0;

			
		
	} while (ch!=6);

	}
	
	delete [] m1;
	return 0;

}
