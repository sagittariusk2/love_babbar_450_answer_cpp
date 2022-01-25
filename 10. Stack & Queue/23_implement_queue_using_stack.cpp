/**
 * @file _implement_queue_using_stack
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 18:26
 * @link https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#
 * @copyright Copyright (c) 2022
 */

#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}
// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x) {
    if(s1.empty()) {
        s2.push(x);
    } else {
        s1.push(x);
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop() {
    if(s1.empty() and s2.empty()) return -1;
    if(s1.empty()) {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        int x = s1.top();
        s1.pop();
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return x;
    } else {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
}
