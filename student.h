#include<string>
#include<iostream>
#include<conio.h>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H
class Student{
	public:
	string first_name;
	string last_name;
	int ID;
	int Student_ID;
	int course;
	int passed;
	float average;
	void set(Student a){
		set(a.first_name,a.last_name,a.ID,a.Student_ID,a.course,a.passed,a.average);
	}
	void set(string f,string l,int i,int si,int c,int p,float a){
		this->first_name=f;
		this->last_name=l;
		this->ID=i;
		this->Student_ID=si;
		this->course=c;
		this->passed=p;
		this->average=a;
	}
	friend operator<<(ostream &out,Student a){
		out<<a.first_name<<"-"<<a.last_name<<"-"<<a.ID<<"-"<<a.Student_ID<<"-"<<a.course<<"-"<<a.passed<<"-"<<a.average<<endl;
	}
	void operator=(Student f){
		this->set(f);
	}
	bool operator==(Student g){
		return this->average==g.average&&this->ID==g.ID&&this->first_name==g.first_name&&this->last_name==g.last_name&&g.passed==this->passed&&g.Student_ID==this->Student_ID&&this->course==g.course;
	}
};
#endif
