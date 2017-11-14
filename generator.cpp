#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int id=1;
int sid=9310003;
int generate_id(){
	return id++;
}
int generate_student_id(){
	return sid+rand()%1000*10;
}
int generate_course(){
	return rand()%9+12;
}
int generate_passed(){
	return rand()%131;
}
float generate_average(){
	float ave=rand()%21;
	if(ave!=20){
		ave+=(float)(rand()%100)/100;
	}
	return ave;
}
string generate_name(){
	string name="";
    name+=('A'+rand()%26);
    int i=rand()%4+5;
  while(i--){
    name+=(char)('a'+rand()%26);
  }
  return name;

}
int main(void){
	ofstream myfile;
	srand(time(NULL));
	myfile.open("mine.txt");
	if(myfile.is_open()){
		for(int i=0;i<100;i++){
			myfile<<generate_name()<<"-"<<generate_name()<<"-"<<generate_id()<<"-"<<generate_student_id()<<"-"<<generate_course()<<"-"<<generate_passed()<<"-"<<generate_average()<<"\n";
		}
	}
	else{
		cout<<"couldn't generate somehow!\nsorry";
		system("PAUSE");
	}
	return 0;
}
