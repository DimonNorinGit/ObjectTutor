#include"stack.h"
namespace Stack{
	const int max_size = 5;
	int head_pointer = -1;
	char stack_array[5];
	bool isEmpty = 1;
}





void Stack::push(char newSimbol){
	if(head_pointer + 1 < max_size){
		stack_array[++head_pointer] = newSimbol;
		isEmpty = 0;
	}else throw OverFlow();
}

char Stack::pop(){
	if(head_pointer > -1){
		return stack_array[head_pointer--];
	}
	else{
		isEmpty = 1;
		return -1;
	}
}

bool Stack::empty(){
	return isEmpty;
}