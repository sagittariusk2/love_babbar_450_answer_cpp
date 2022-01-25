/**
 * @file 06_parenthesis_checker
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 02:18
 * @link https://practice.geeksforgeeks.org/problems/parenthesis-checker/0
 * @copyright Copyright (c) 2022
 */

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x) {
        stack<char> st;
        for(auto i:x) {
            if(i=='{' or i=='[' or i=='(') st.push(i);
            else if(!st.empty()) {
                if((i=='}' and st.top()=='{') or (i==']' and st.top()=='[') or (i==')' and st.top()=='(')) {
                    st.pop();
                }
                else return false;
            } else return false;
        }
        if(st.empty()) return true;
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends