#include<map>
#include<iostream>
#include<queue>


int main(){
	std::queue<int> q;
	q.push(1);
	q.push(2);
	std::cout<<q.front();
	
	return 0;
}