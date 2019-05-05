#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <conio.h>
#include "student.h"
#include "calculatecgpa.h"
#include "marks.h"
using namespace std;
int student_counter=0;


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
	int ch=4;
	while(ch==4)
	{
	mainDisplay();
	cout<<"\n\n\nEnter 'yes' if you want to create a file to save all your input data later or enter any other character if you dont want to:";
	string input;
	cin>>input;
	marks* m1;
	m1=new marks [100];
	if(input=="yes" || input=="YES")
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
	ofstream makefile(filed,fstream::app);
	
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
		system("CLS");
		
			if(ch==1)
			{
			cout<<"\n\nPlease insert the number of students you wish to entered the information to:";
			int inf;
			cin>>inf;
			for(int i=student_counter;i<inf+student_counter;i++)
			{
			m1[i].getdata();
			m1[i].intofile(makefile);
			m1[i].inputfile(makefile);
			}
			student_counter=student_counter+inf;

			exit;
			}
			
 
			else if(ch==2)
			{
			cout<<"Please enter the matric id of the students you want to search:";
			string searching;
			int temp=1000;
			cin.ignore(10000,'\n');
			getline(cin,searching);
			for(int i=0;i<100;i++)
			{
				if(m1[i].search(searching)==1)
				{cout<<"found"<<endl;
					temp=i;
				m1[temp].output();}
				if(i==99 && temp==1000)
				{
					cout<<"There is no designated matric id in the database"<<endl;
					cout<<"Please press any key to continue"<<endl;
					_getch();
					exit;
				}
			}
			
			exit;
			
			}
 
			else if(ch==3)
			{
			string line,comma_string,outfiled;
			string a,b,c,d,temp[6];
			int e,etemp=0,i;
			int count=0;
			float f;
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
			f=atof(temp[5].c_str());
			m1[student_counter].outfromfile(a,b,c,d,e,f);
			student_counter++;
				count++;
			}
			gototheinput.close();
			student_counter=student_counter-count;
			for(int i=student_counter;i<count+student_counter;i++)
			{
				m1[i].putdata();
			}
			student_counter=student_counter+count;
			cout<<"\n\nDo you want to \n[A]dd data to your file?\n[R]emove data on your file\n(Enter A or R if you want to and enter any other character if you dont):";
			string addData,newFile;
			cin>>addData;
			if(addData=="A")
			{

			cout<<"Please create a new file (Any name):";
			cin.ignore(10000,'\n');
			getline(cin,newFile);
	
				cout<<"\n";
			newFile.append(".txt");
			ofstream makenewfile(newFile);
			student_counter=student_counter-count;
			for(int i=student_counter;i<count+student_counter;i++)
			{
			m1[i].intoNewfile(makenewfile);
			}
			student_counter=student_counter+count;
			cout<<"\n\nPlease insert the number of students you wish to entered the information to:";
			int infinite;
			cin>>infinite;
			for(int i=student_counter;i<infinite+student_counter;i++)
			{
			m1[i].getdata();
			m1[i].intofile(makenewfile);
			m1[i].inputfile(makenewfile);
			}
			student_counter=student_counter+infinite;
			makenewfile.close();
			exit;
			}
			else if(addData=="R")
			{
				cout<<"Please create a new file (Any name):";
			cin.ignore(10000,'\n');
			getline(cin,newFile);
	
				cout<<"\n";
			newFile.append(".txt");
			ofstream makenewfile(newFile);
			student_counter=student_counter-count;
			int j=0;
			for(int i=student_counter;i<count+student_counter;i++)
			{
				
			cout<<"\n["<<j+1<<"]";
			m1[i].putdata();
			cout<<"\n";
			j++;
			}
			cout<<"Please select which students data you want to remove by entering number index:";
			int index;
			cin>>index;
		index=index-1;
					for(int i=student_counter+index;i<count+student_counter;i++)
			{
				m1[i]=m1[i+1];
			
			}
				
			
			for(int i=student_counter;i<count+student_counter-1;i++)
			{
			m1[i].intoNewfile(makenewfile);
			}

			student_counter=student_counter+count-1;
			makenewfile.close();
			exit;
			}
			else
				exit;
			}
			else if(ch==4)
			{makefile.close();}
			
		
	} while (ch!=5 && ch!=4);
	makefile.close();
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
		system("CLS");
			if(ch==1)
			{
			cout<<"\n\nPlease insert the number of students you wish to entered the information to:";
			int inf;
			cin>>inf;

			for(int i=student_counter;i<inf+student_counter;i++)
			{
			m1[i].getdata();
			m1[i].input();
			}
			student_counter=student_counter+inf;
			exit;
			}
			
 
			else if(ch==2)
			{
			cout<<"Please enter the matric id of the students you want to search:";
			string searching;
			int temp=1000;
			cin.ignore(10000,'\n');
			getline(cin,searching);
			for(int i=0;i<100;i++)
			{
				if(m1[i].search(searching)==1)
				{cout<<"found"<<endl;
					temp=i;
				m1[temp].output();}
				if(i==99 && temp==1000)
				{
					cout<<"There is no designated matric id in the database"<<endl;
					cout<<"Please press any key to continue"<<endl;
					_getch();
					exit;
				}
			}
			
			exit;
			}
 
			else if(ch==3)
			{
			string line,comma_string,outfiled;
			string a,b,c,d,temp[6];
			int e,etemp=0,i;
			int count=0;
			float f;
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
			f=atof(temp[5].c_str());
			m1[student_counter].outfromfile(a,b,c,d,e,f);
			student_counter++;
				count++;
			}
			gototheinput.close();
			student_counter=student_counter-count;
			for(int i=student_counter;i<count+student_counter;i++)
			{
				m1[i].putdata();
				cout << endl;
			}
			student_counter=student_counter+count;
			cout<<"\n\nDo you want to \n[A]dd data to your file?\n[R]emove data on your file\n(Enter A or R if you want to and enter any other character if you dont):";
			string addData,newFile;
			cin>>addData;
			if(addData=="A")
			{

			cout<<"Please create a new file (Any name):";
			cin.ignore(10000,'\n');
			getline(cin,newFile);
	
				cout<<"\n";
			newFile.append(".txt");
			ofstream makenewfile(newFile);
			student_counter=student_counter-count;
			for(int i=student_counter;i<count+student_counter;i++)
			{
			m1[i].intoNewfile(makenewfile);
			}
			student_counter=student_counter+count;
			cout<<"\n\nPlease insert the number of students you wish to entered the information to:";
			int infinite;
			cin>>infinite;
			for(int i=student_counter;i<infinite+student_counter;i++)
			{
			m1[i].getdata();
			m1[i].intofile(makenewfile);
			m1[i].inputfile(makenewfile);
			}
			student_counter=student_counter+infinite;
			makenewfile.close();
			exit;
			}
			else if(addData=="R")
			{
				cout<<"Please create a new file (Any name):";
			cin.ignore(10000,'\n');
			getline(cin,newFile);
	
				cout<<"\n";
			newFile.append(".txt");
			ofstream makenewfile(newFile);
			student_counter=student_counter-count;
			int j=0;
			for(int i=student_counter;i<count+student_counter;i++)
			{
				
			cout<<"\n["<<j+1<<"]";
			m1[i].putdata();
			cout<<"\n";
			j++;
			}
			cout<<"Please select which students data you want to remove by entering number index:";
			int index;
			cin>>index;
		index=index-1;
					for(int i=student_counter+index;i<count+student_counter;i++)
			{
				m1[i]=m1[i+1];
			
			}
				
			
			for(int i=student_counter;i<count+student_counter-1;i++)
			{
			m1[i].intoNewfile(makenewfile);
			}

			student_counter=student_counter+count-1;
			makenewfile.close();
			exit;
			}
			else
				exit;
			}
		

			
		
	} while (ch!=5 && ch!=4);

	}
	
	delete [] m1;
	}
	return 0;
}