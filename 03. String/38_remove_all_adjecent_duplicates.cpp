/*
    Question link :- (https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1)
    Question :- Remove Consecutive Characters
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

string removeConsecutiveCharacter(string S) {
    string ans;
    ans += S[0];
    for(int i=1; i<S.size(); i++) {
        if(S[i]!=S[i-1]) ans += S[i];
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin >> str;
        cout<<removeConsecutiveCharacter(str)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(i)
*/