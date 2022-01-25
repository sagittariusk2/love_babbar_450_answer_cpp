/**
 * @file 12_evaluation_of_postfix_expression
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 12:39
 * @link https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
 * @copyright Copyright (c) 2022
 */

// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S) {
        // Your code here
        stack<int> s1;
        for(auto i:S) {
            if(i>='0' and i<='9') {
                s1.push(i-48);
            } else {
                int a = s1.top();
                s1.pop();
                int b = s1.top();
                s1.pop();
                int c;
                if(i=='+') {
                    c = a+b;
                } else if(i=='-') {
                    c = b-a;
                } else if(i=='*') {
                    c = b*a;
                } else {
                    c = b/a;
                }
                s1.push(c);
            }
        }
        return s1.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends