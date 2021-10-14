/*
    Question link :- (https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1)
    Question :- Wildcard string matching
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool solve(int i, int j, string wild, string pattern) {
    if(i==-1 and j==-1) return true;
    if(i==-1) return false;
    if(j==-1) return false;
    if(wild[i]=='*') {
        if(i==0) return true;
        return (solve(i-1, j, wild, pattern) or solve(i, j-1, wild, pattern));
    } else if(wild[i]=='?' or (wild[i]==pattern[j])) {
        return solve(i-1, j-1, wild, pattern);
    } else {
        return false;
    }
}

bool match(string wild, string pattern) {
    int n = wild.size(), m = pattern.size();
    return solve(n-1, m-1, wild, pattern);
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string wild, pattern;
        cin >> wild >> pattern;
        cout << match(wild, pattern) << "\n";
    }
}

/*
    Time Complexity :- O(n*m)
    Space Complexity :- O(1)
*/