#include<iostream>
#include<fstream>
#include"stack.h"

using namespace std;
using namespace Stack;
int main(){

	ifstream fin("input.txt");

	char simbol;
	while(!fin.eof()){
		fin >> simbol;
		try{
			Stack::push(simbol);
		}
		catch(Stack::OverFlow){
			cout<<"stack Overflow !";
		}
	}


	while(!Stack::empty()){
		cout << Stack::pop() <<":" << endl;
	}
	

	return 0;
}