#define null 0
#include"student.h"
template<class T>
class node{
	public:
	node* right;
	node* left;
	Student data;
	T key;
	node(){
		left=right=null;
	}
};
