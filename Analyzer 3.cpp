#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

class Evaluate {
protected:
	string qualify;
	float lcgpa;
	char grade;
public:
	Evaluate() : lcgpa(0),qualify(" "),grade(' ') {}
	Evaluate(float def_cgpa,string def_qualify,char def_grade) :lcgpa(def_cgpa),qualify(def_qualify),grade(def_grade) {}
	virtual void evaluation() {
		cout << "Cgpa !!!Whyyyy [- "
			<< qualify << "(qualification)" << endl
			<<to_string((char)grade) <<"(grade)"
		<< to_string((float)lcgpa) << "(cgpa)" << endl;
	}
};

class TopExcellent : public Evaluate {
public:
	TopExcellent() :Evaluate(4.0-3.0,"Undergraduate",'A') {}
	void evaluate() {
		cout << "We have nothing to teach you [-"<<
		qualify<<"(qualification)"<<
		to_string((char)grade)<<"(grade)"<<
		to_string((float)lcgpa)<<"(cgpa)";
	}
};

class Excellent : public Evaluate {
public:
	Excellent():Evaluate(4.0 - 3.0,"",'A') {}
	void evaluate() {
		cout << "We have nothing to teach you [-" <<
			qualify << " (qualification) " <<
			to_string((char)grade) << " (grade) "<<
			to_string((float)lcgpa) << " (cgpa) ";
	}
};

class Student {
	string matric;
	string name;
	string addr;
	string course;
	int current_sem;
	Evaluate* qualify;
	Evaluate* grade;
	Evaluate* lcgpa;
public:
	Student() { matric = " ", name = " ", addr = " ", current_sem = 0, qualify = NULL, grade = NULL, lcgpa = NULL; }
	Student(string stud_matric, string stud_name, string stud_addr, string stud_course, int stud_current_sem) :
		matric(stud_matric), name(stud_name), addr(stud_addr), course(stud_course), current_sem(stud_current_sem), lcgpa(0), qualify(NULL), grade(NULL) {

	}
	void setQualify(Evaluate* q) { qualify = q; }
	void setGrade(Evaluate* g) { grade = g; }
	void setLcgpa(Evaluate* l) { lcgpa = l; }
	void doEvaluation() {
		if (lcgpa == 0 && qualify == NULL && grade == NULL)
			cout << " (Student) " << name << " : you don't have qualification or a grade or a cgpa at all." << endl;
		else;
			lcgpa->evaluation();
	}
	string getInfo() {
		cout << " Enter matric id: ";
		getline(cin, matric);
		cout << "\n Enter the student name:";
		getline(cin, name);
		cout << "\n Enter the student address:";
		getline(cin, addr);
		cout << "\n Enter the student course:";
		getline(cin, course);
		cout << "\n Enter the current semester for the student:";
		cin >> current_sem;
		return name + matric + addr + course;

	}

};

int main() {
	TopExcellent topexcellent;
	Excellent excellent;
	Student s1((string)"A18CS0263","Joe","208 KTDI","SCSR",(int)"2");
	s1.doEvaluation();

	/*s1.setQualify(&topexcellent);
	s1.doEvaluation();

	s1.setQualify(&excellent);
	s1.doEvaluation();*/



	}
