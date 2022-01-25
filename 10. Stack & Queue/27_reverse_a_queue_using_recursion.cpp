/**
 * @file 27_reverse_a_queue_using_recursion
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 15:17
 * @link https://practice.geeksforgeeks.org/problems/queue-reversal/1
 * @copyright Copyright (c) 2022
 */

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.

void solve(queue<int> &q) {
    if(!q.empty()) {
        int x = q.front();
        q.pop();
        solve(q);
        q.push(x);
    }
}

queue<int> rev(queue<int> q) {
    solve(q);
    return q;
}