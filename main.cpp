#include"tree.h"
#include"console.h"
int main(void){
	int which;
	float whuch;
	string whoch;
	vector<node<int>* > find;
	vector<node<float>* > findad;
	vector<node<string>* > finded;
	bst<int> id;
	console Console;
	bst<int> student_id;
	bst<string> first_name;
	bst<string> last_name;
	bst<int> courses;
	bst<int> passed;
	bst<float> average;
	Student b;
	int del;
	string file_name_load="mine";
	string file_name_save="mine";
	bool continued=true;
	char choice_main,choice_other,last_choice;
	vector<Student> stu;
	do{
		choice_main=Console.show_menu();
		switch(choice_main){
			case '0':{
				continued=false;
				break;
			}
			case '1':{
				cout<<"do you want not to use default file name?(y/*)\n";
				if(getch()=='y'){
				cin>>file_name_load;	
				}
				stu=id.load(file_name_load);
				for(int i=0;i<stu.size();i++){
					id.insert(stu[i],stu[i].ID);
					student_id.insert(stu[i],stu[i].Student_ID);
					courses.insert(stu[i],stu[i].course);
					passed.insert(stu[i],stu[i].passed);
					first_name.insert(stu[i],stu[i].first_name);
					last_name.insert(stu[i],stu[i].last_name);
					average.insert(stu[i],stu[i].average);
				}
				break;
			}
			case '2':{
				cout<<"do you want not to use default file name?(y/*)\n";
				if(getch()=='y'){
				cin>>file_name_save;	
				}
				ofstream myfile;
				choice_other=Console.show_find_delete_show_save_menu();
				switch(choice_other){
					case '1':{
						id.save(myfile,file_name_save);
						break;
					}
					case '2':{
						student_id.save(myfile,file_name_save);
						break;
					}
					case '3':{
						first_name.save(myfile,file_name_save);
						break;
					}
					case '4':{
						last_name.save(myfile,file_name_save);
						break;
					}
					case '5':{
						average.save(myfile,file_name_save);
						break;
					}
					case '6':{
						courses.save(myfile,file_name_save);
						break;
					}
					case '7':{
						passed.save(myfile,file_name_save);
						break;
					}
				}
				break;
			}
			case '3':{
				b=Console.show_insert();
				id.insert(b,b.ID);
				student_id.insert(b,b.Student_ID);
				first_name.insert(b,b.first_name);
				last_name.insert(b,b.last_name);
				average.insert(b,b.average);
				passed.insert(b,b.passed);
				courses.insert(b,b.course);
				break;
			}
			case '4':{
				choice_other=Console.show_find_delete_show_save_menu(true);
				switch(choice_other){
					case '1':{
						cout<<"give me his/her id :\n";
						cin>>which;
						find=id.find(which);
						for(int i=0;i<find.size();i++)
							cout<<i<<"-"<<find[i]->data;
						if(find.size()!=0){
							cin>>del;
							if(del<find.size()){	
								id.deleted(find[del]->data.ID,find[del]->data);
								student_id.deleted(find[del]->data.Student_ID,find[del]->data);
								average.deleted(find[del]->data.average,find[del]->data);
								first_name.deleted(find[del]->data.first_name,find[del]->data);
								last_name.deleted(find[del]->data.last_name,find[del]->data);
								passed.deleted(find[del]->data.passed,find[del]->data);
								courses.deleted(find[del]->data.course,find[del]->data);	
							}
						}
						break;
					}
					case '2':{
						cout<<"give me his/her student id :\n";
						cin>>which;
						find=student_id.find(which);
						for(int i=0;i<find.size();i++)
							cout<<i<<"-"<<find[i]->data;
						if(find.size()!=0){
							cin>>del;
							if(del<find.size()){	
								id.deleted(find[del]->data.ID,find[del]->data);
								student_id.deleted(find[del]->data.Student_ID,find[del]->data);
								average.deleted(find[del]->data.average,find[del]->data);
								first_name.deleted(find[del]->data.first_name,find[del]->data);
								last_name.deleted(find[del]->data.last_name,find[del]->data);
								passed.deleted(find[del]->data.passed,find[del]->data);
								courses.deleted(find[del]->data.course,find[del]->data);	
							}
						}
						break;
					}
					case '3':{
						cout<<"give me his/her first name :\n";
						cin>>whoch;
						finded=first_name.find(whoch);		
						for(int i=0;i<finded.size();i++)
							cout<<i<<"-"<<finded[i]->data;
							
						if(find.size()!=0){	
							cin>>del;
							if(del<finded.size()){	
								id.deleted(finded[del]->data.ID,finded[del]->data);
								student_id.deleted(finded[del]->data.Student_ID,finded[del]->data);
								average.deleted(finded[del]->data.average,finded[del]->data);
								first_name.deleted(finded[del]->data.first_name,finded[del]->data);
								last_name.deleted(finded[del]->data.last_name,finded[del]->data);
								passed.deleted(finded[del]->data.passed,finded[del]->data);
								courses.deleted(finded[del]->data.course,finded[del]->data);	
							}
						}
						break;
					}
					case '4':{
						cout<<"give me his/her last name :\n";
						cin>>whoch;
						finded=last_name.find(whoch);
						for(int i=0;i<finded.size();i++)
							cout<<i<<"-"<<finded[i]->data;
							
						if(find.size()!=0){	
							cin>>del;
							if(del<finded.size()){	
								id.deleted(finded[del]->data.ID,finded[del]->data);
								student_id.deleted(finded[del]->data.Student_ID,finded[del]->data);
								average.deleted(finded[del]->data.average,finded[del]->data);
								first_name.deleted(finded[del]->data.first_name,finded[del]->data);
								last_name.deleted(finded[del]->data.last_name,finded[del]->data);
								passed.deleted(finded[del]->data.passed,finded[del]->data);
								courses.deleted(finded[del]->data.course,finded[del]->data);	
							}
						}
						break;
					}
					case '5':{
						cout<<"give me his/her average :\n";
						cin>>whuch;
						findad=average.find(whuch);
						for(int i=0;i<findad.size();i++)
							cout<<i<<"-"<<findad[i]->data;
							
						if(find.size()!=0){	
							cin>>del;
							if(del<findad.size()){	
								id.deleted(findad[del]->data.ID,findad[del]->data);
								student_id.deleted(findad[del]->data.Student_ID,findad[del]->data);
								average.deleted(findad[del]->data.average,findad[del]->data);
								first_name.deleted(findad[del]->data.first_name,findad[del]->data);
								last_name.deleted(findad[del]->data.last_name,findad[del]->data);
								passed.deleted(findad[del]->data.passed,findad[del]->data);
								courses.deleted(findad[del]->data.course,findad[del]->data);
							}
						}
						break;
					}
					case '6':{
						cout<<"give me his/her courses :\n";
						cin>>which;
						find=courses.find(which);
						for(int i=0;i<find.size();i++)
							cout<<i<<"-"<<find[i]->data;
							
						if(find.size()!=0){	
							cin>>del;
							if(del<find.size()){
								id.deleted(find[del]->data.ID,find[del]->data);
								student_id.deleted(find[del]->data.Student_ID,find[del]->data);
								average.deleted(find[del]->data.average,find[del]->data);
								first_name.deleted(find[del]->data.first_name,find[del]->data);
								last_name.deleted(find[del]->data.last_name,find[del]->data);
								passed.deleted(find[del]->data.passed,find[del]->data);
								courses.deleted(find[del]->data.course,find[del]->data);
							}
						}
						break;
					}
					case '7':{
						cout<<"give me his/her passed courses :\n";
						cin>>which;
						find=passed.find(which);
						for(int i=0;i<find.size();i++)
							cout<<i<<"-"<<find[i]->data;
						if(find.size()!=0){
							cin>>del;
							if(del<find.size()){	
								id.deleted(find[del]->data.ID,find[del]->data);
								student_id.deleted(find[del]->data.Student_ID,find[del]->data);
								average.deleted(find[del]->data.average,find[del]->data);
								first_name.deleted(find[del]->data.first_name,find[del]->data);
								last_name.deleted(find[del]->data.last_name,find[del]->data);
								passed.deleted(find[del]->data.passed,find[del]->data);
								courses.deleted(find[del]->data.course,find[del]->data);	
							}
						}
						break;
					}
				}
				break;
			}
			case '5':{
				choice_other=Console.show_find_delete_show_save_menu();
				switch(choice_other){
					case '1':{
						cout<<"give me his/her id :\n";
						cin>>which;
						find=id.find(which);
							for(int i=0;i<find.size();i++)
								cout<<find[i]->data;
						break;
					}
					case '2':{
						cout<<"give me his/her student id :\n";
						cin>>which;
						find=student_id.find(which);
						for(int i=0;i<find.size();i++)
							cout<<find[i]->data;
						break;
					}
					case '3':{
						cout<<"give me his/her first name :\n";
						cin>>whoch;
						finded=first_name.find(whoch);		
						for(int i=0;i<finded.size();i++)
							cout<<finded[i]->data;
						break;
					}
					case '4':{
						cout<<"give me his/her last name :\n";
						cin>>whoch;
						finded=last_name.find(whoch);
						for(int i=0;i<finded.size();i++)
							cout<<finded[i]->data;
						break;
					}
					case '5':{
						cout<<"give me his/her average :\n";
						cin>>whuch;
						findad=average.find(whuch);
						for(int i=0;i<findad.size();i++)
							cout<<findad[i]->data;
						break;
					}
					case '6':{
						cout<<"give me his/her courses :\n";
						cin>>which;
						find=courses.find(which);
						for(int i=0;i<find.size();i++)
							cout<<find[i]->data;
						break;
					}
					case '7':{
						cout<<"give me his/her passed courses :\n";
						cin>>which;
						find=passed.find(which);
						for(int i=0;i<find.size();i++)
							cout<<find[i]->data;
						break;
					}
				}
				break;
			}
			case '6':{
				choice_other=Console.show_find_delete_show_save_menu();
				switch(choice_other){
					case '1':{
						id.inorder(id.root);
						break;
					}
					case '2':{
						student_id.inorder(student_id.root);
						break;
					}
					case '3':{
						first_name.inorder(first_name.root);
						break;
					}
					case '4':{
						last_name.inorder(last_name.root);
						break;
					}
					case '5':{
						average.inorder(average.root);
						break;
					}
					case '6':{
						courses.inorder(courses.root);
						break;
					}
					case '7':{
						passed.inorder(passed.root);
						break;
					}
				}
				break;
			}
			case '7':{
				Console.show_about();
				break;
			}
			case '8':{
				cout<<"welcome to secret generator\n";
				system("pause");
				system("D:");
				system("cd Ds\project DS\manager");
				system("generator.exe");
				cout<<"i done generating \n";
				break;
			}
		}
		system("pause");
	}while(continued);
	return 0;
}
