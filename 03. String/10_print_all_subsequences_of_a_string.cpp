/*
    Question link :- (https://www.geeksforgeeks.org/print-subsequences-string/)
    Question :- Print all Subsequences of a string.
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

set<string> allSubsequence(string S) {
    int n=S.length();
    set<string> ans;
    int x = pow(2, n);
    for(int i=1; i<x; i++) {
        string str = bitset<32>(i).to_string(), temp;
        for(int j=32-n; j<32; j++) {
            if(str[j]=='1') temp += S[j-32+n];
        }
        ans.insert(temp);
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        set<string> ans = allSubsequence(s);
        for(auto i:ans) cout<<i<<" ";
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(2^n)
    Space Complexity :- O(1)
*/
