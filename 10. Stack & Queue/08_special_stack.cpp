/**
 * @file 08_special_stack
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 02:33
 * @link https://practice.geeksforgeeks.org/problems/special-stack/1#
 * @copyright Copyright (c) 2022
 */

#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

int mn = 1e5;

void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
	mn = min(mn, a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return (s.size()>=n);
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.empty()) {
	    mn = 1e5;
	}
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	int x = s.top();
	s.pop();
	return x;
}

int getMin(stack<int>& s){
	// Your code goes here
	return mn;
}