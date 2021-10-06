/*
    Question link :- (https://leetcode.com/problems/reverse-string/)
    Question :- Reverse String
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void reverseString(string s) {
    int n = s.size();
    int x = n/2;
    char y;
    for(int i=0; i<x; i++) {
        swap(s[i], s[n-i-1]);
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        reverseString(s);
        cout<<s<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
