#include<iostream>
#include<stdlib.h>
#include<fstream>
#include"node.h"
#include<stack>
#include<queue>
#include<vector>
template <class T>
class bst{
	public:
	node<T>* root;
	bst(){
		root=null;
	}	
	void insert_left(node<T>* t,Student s,T key){
		node<T>* f=new node<T>;
		f->data.set(s);
		f->key=key;
		t->left=f;
	}
	void insert_right(node<T>* t,Student s,T key){
		node<T>* f=new node<T>;
		f->data.set(s);
		f->key=key;
		t->right=f;
	}
	void insert(Student a,T key){
		if(root==null){
			root=new node<T>;
			root->data.set(a);
			root->key=key;
		}
		else{
			node<T>* cur=root;
			while(cur){
				if(cur->key>=key){
					if(cur->left){
						cur=cur->left;
					}
					else{
						insert_left(cur,a,key);
						break;
					}
				}
				else {
					if(cur->right){
						cur=cur->right;
					}
					else{
						insert_right(cur,a,key);
						break;
					}
				}
			}
		}
	}
	void inorder(node<T>* cur){
		if(cur){
			if(cur->left){
				inorder(cur->left);
			}
				cout<<cur->data;
			
			if(cur->right){
				inorder(cur->right);
			}
		}
	}
	vector<node<T>*> find(T key){
		vector<node<T>*> forReturn;
		node<T>* cur=root;
		while(cur){
			if(cur->key>key){
				cur=cur->left;
			}
			else if(cur->key<key){
				cur=cur->right;
			}
			else{
				forReturn.push_back(cur);
				while(true){
					if(cur->left){	
						if(cur->left->key==cur->key){
							cur=cur->left;
							forReturn.push_back(cur);	
						}
						else{
							break;
						}
					}
					else{
						break;
					}
				}
				return forReturn;
			}
		}
		//return null;
		return forReturn;
	}
	void  deleted(T key,Student b){
		vector<node<T>* > my=find(key);
		int hold=my.size();
		for(int i=0;i<my.size();i++){
			if(my[i]->data==b){
				hold=i;
			}
		}
		if(hold!=my.size()){
			node<T>* parent=findParrent(my[hold]);
			node<T>* child=my[hold];
			if(child){
				if(child->left==null&&child->right==null){
					if(child==root){
						delete child;
						root=null;
					}
					else{
						if(parent->left==child){
							delete child;
							parent->left=null;
						}
						else{
							delete child;
							parent->right=null;
						}
					}
				}
				else if(child->left==null){
					if(child!=root){
						if(parent->left==child){
							parent->left=child->right;
							delete child;
						}
						else{
							parent->right=child->right;
							delete child;
						}
					}
					else{
						root=root->right;
						delete child;
					}
				}
				else if(child->right==null){
					if(root!=child){
						if(parent->left==child){
							parent->left=child->left;
							delete child;
						}
						else{
							parent->right=child->left;
							delete child;
						}
					}
					else{
						root=root->left;
						delete child;
					}
				}
				else{
					node<T>* par=child;
					node<T>* cur=child->right;
					while(cur->left){
						par=cur;
						cur=cur->left;
					}
					child->key=cur->key;
					child->data.set(cur->data);
					_deleted(cur,par);
				}
			}
		}
	}
	void _deleted(node<T>* child,node<T>* parent){
		if(child->left==null&&child->right==null){
			if(child==root){
				delete child;
				root=null;
			}
			else{
				if(parent->left==child){
					delete child;
					parent->left=null;
				}
				else{
					delete child;
					parent->right=null;
				}
			}
		}
		else if(child->left==null){
			if(parent->left==child){
				parent->left=child->right;
				delete child;
			}
			else{
				parent->right=child->right;
				delete child;
			}
		}
		else if(child->right==null){
			if(parent->left==child){
				parent->left=child->left;
				delete child;
			}
			else{
				parent->right=child->left;
				delete child;
			}
		}
		else{
			node<T>* par=child;
			node<T>* cur=child->right;
			while(cur->left){
				par=cur;
				cur=cur->left;
			}
			child->key=cur->key;
			child->data.set(cur->data);
			_deleted(cur,par);
		}
	}
	
	node<T>* findParrent(node<T>* col){
		node<T>* cur=root;
		queue<node<T>* > q;
		q.push(cur);
		while(true){
			if(q.empty()){
				break;
			}
			else{
				cur=q.front();
				q.pop();
				if(cur->left){
					if(cur->left==col){
						return cur;
					}
					else{
						q.push(cur->left);
					}
				}
				if(cur->right){
					if(cur->right==col){
						return cur;
					}
					else{
						q.push(cur->right);
					}
				}
			}
		}
		return null;
	}
void save(ofstream &myfile,string name){
	name+=".txt";
    myfile.open (name.c_str());
	node<T>* cur=root;
	stack<node<T>*> st;
	
	while(true){
		while(cur){
			st.push(cur);
			cur=cur->left;
		}
		if(!st.empty()){
			cur=st.top();
			st.pop();
			myfile<<cur->data;
			cur=cur->right;
		}
		else{
			break;
		}
	}
  	myfile.close();
}

vector<string> split(const char *str, char c = ' '){
    vector<string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}
int matoi(string a){
	int r=0;
	for(int i=0;i<a.size();i++){
		r*=10;
		r+=(a.at(i)-'0');
	}
	return r;
}
vector<Student> load(string name){
	name+=".txt";
	string line;
	vector<string> elements;
	vector<Student> alled;
	Student temp;
	delete root;
	root=null;
	ifstream myfile(name.c_str());
	 if (myfile.is_open())
  {
	while ( getline (myfile,line) )
    {
      elements=split(line.c_str(),'-');
      
      temp.set(elements[0],elements[1],matoi(elements[2]),matoi(elements[3]),matoi(elements[4]),matoi(elements[5]),atof(elements[6].c_str()));
      alled.push_back(temp);
	  elements.clear();
    	}
    	myfile.close();
    	return alled;
	}
	else{
		cout<<"couldn't open it";
	}
}
};
