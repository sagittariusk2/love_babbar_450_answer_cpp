/*
    Question link :- (https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/)
    Question :- Transform One String to Another using Minimum Number of Given Operation
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int transform(string str1, string str2) {
    if(str1.length() != str2.length()) return -1;
    vector<int> mp1(26, 0), mp2(26, 0);
    for(auto i:str1) {
        mp1[i-'A']++;
    }
    for(auto i:str2) {
        mp2[i-'A']++;
    }
    for(int i=0; i<26; i++) {
        if(mp1[i]!=mp2[i]) return -1;
    }
    int n = str1.length();
    for(int i=n-1; i>=0; i--) {
        if(str1[i]!=str2[i]) return i;
    }
    return 0;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str1, str2;
        cin >> str1 >> str2;
        cout<<transform(str1, str2)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/