/*
    Question link :- (https://practice.geeksforgeeks.org/problems/parenthesis-checker/0)
    Question :- Balanced Parenthesis problem.[Imp]
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

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

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<ispar(s)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/