/*
    Question link :- (https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1)
    Question :- Isomorphic Strings
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool areIsomorphic(string str1, string str2) {
    if(str1.size()!=str2.size()) return false;
    int v1[26], v2[26];
    memset(v1, -1, sizeof(v1));
    memset(v2, -1, sizeof(v2));
    int n=str1.length();
    for(int i=0; i<n; i++) {
        if(v1[str1[i]-97]==-1 and v2[str2[i]-97]==-1) {
            v1[str1[i]-97] = str2[i]-97;
            v2[str2[i]-97] = str1[i]-97;
        } else if(v1[str1[i]-97]!=-1 and v2[str2[i]-97]!=-1) {}
        else return false;
    }
    return true;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str1, str2;
        cin>>str1>>str2;
        cout<<areIsomorphic(str1, str2)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/