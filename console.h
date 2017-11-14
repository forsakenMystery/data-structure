#include<iostream>
#include"Student.h"
#include<conio.h>
#define end 27
using namespace std;
class console{
	public:
	char show_menu(){
		system("cls");
		system("color 1e");
		cout<<"welcome manager\n"
			<<"what do you want to do?\n"
			<<"0-exit my program\n"
			<<"1-load previous data\n"
			<<"2-save new data\n"
			<<"3-insert new students\n"
			<<"4-delete students\n"
			<<"5-find a student\n"
			<<"6-show them\n"
			<<"7-about me\n";
		return getch();
	}
	void show_about(){
		do{
			system("cls");
			system("color 1e");
			cout<<"hello and welcome to my manager\n"
				<<"my nickname is forsakenMystery and my id on telegram is @forsakenMystery\n"
				<<"please tell me your suggestion\n"
				<<"press Esc to return\n"
				<<"with thanks\n";
		}while(getch()!=end);
	}
	char show_find_delete_show_save_menu(bool del=false){
		system("cls");
		system("color 1e");
		cout<<"welcome to do the thing on students\n"
			<<"1-by id\n"
			<<"2-by student id\n"
			<<"3-by first name\n"
			<<"4-by last name\n"
			<<"5-by average\n"
			<<"6-by courses in this semester\n"
			<<"7-by passed till now\n";
			if(del){
				cout<<"8-delete unique\n";
			}
		return getch();
	}
	Student show_insert(){
		string name,last;
		int id,sid,cour,pass;
		float avg;
		system("cls");
		system("color 1e");
		cout<<"welcome to insert/delete a student\n"
			<<"give me his/her first name\n";
		cin>>name;
		cout<<"give me his/her last name\n";
		cin>>last;
		cout<<"give me his/her ID\n";
		cin>>id;
		cout<<"give me his/her student id\n";
		cin>>sid;
		cout<<"give me his/her courses in this semester\n";
		cin>>cour;
		cout<<"give me his/her passed courses till now\n";
		cin>>pass;
		cout<<"give me his/her average\n";
		cin>>avg;
		Student forReturn;
		forReturn.set(name,last,id,sid,cour,pass,avg);
		return forReturn;
	}
	
};
