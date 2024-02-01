// You are given a stack ‘S’. Your task is to sort the sack recursively.



// Note:
// Looping through the stack is not allowed.
// You need to return a stack that is sorted in descending order.


// For example:
// Given stack S = 1 3 2 
// The output will be 3 2 1 since it is the sorted order.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 2
// 4
// 1 0 0 2 
// 3 
// 2 4 2
// Sample Output 1 :
// 2 1 0 0
// 4 4 2

#include <bits/stdc++.h> 

void insert_into_stack(stack<int>&s, int temp){
	if(s.empty() || temp> s.top()){
		s.push(temp);
		return;
	}
	int x = s.top();
	s.pop();
	insert_into_stack(s,temp);
	s.push(x);
	return;
}

stack<int> sortStack(stack<int> &s)
{
	if(s.empty()) return s;

	int temp = s.top();
	s.pop();

	sortStack(s);

	insert_into_stack(s, temp);
	return s;
}
