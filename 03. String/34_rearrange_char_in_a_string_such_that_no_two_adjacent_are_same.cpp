/*
    Question link :- (https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems)
    Question :- Rearrange Characters
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        vector<int> v1(26, 0);
        for(auto i:s) {
            v1[i-'a']++;
        }
        int n=s.size(), x=(n+1)/2, f=0;
        for(int i=0; i<26; i++) {
            if(x<v1[i]) {
                cout<<"0\n";
                f++;
                break;
            }
        }
        if(f==0)
        cout<<"1\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/