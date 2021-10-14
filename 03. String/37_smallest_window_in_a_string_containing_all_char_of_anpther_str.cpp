/*
    Question link :- (https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1)
    Question :- Smallest window in a string containing all the characters of another string
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool equal(vector<int> &mpp, vector<int> &curr_mpp) {
    for(int i=0; i<52; i++) {
        if(curr_mpp[i]<mpp[i]) return false;
    }
    return true;
}

string smallestWindow (string s, string p) {
    vector<int> mpp(52, 0), curr_mpp(52, 0);
    for(auto i:p) {
        if(i>='a' and i<='z') mpp[i-97]++;
        else mpp[i-39]++;
    }

    int n=s.size();
    int i=0, j=0, ii=0, jj=0, ans=n;
    while(i<n and j<n) {
        if(s[j]>='a' and s[j]<='z') curr_mpp[s[j++]-97]++;
        else curr_mpp[s[j++]-39]++;
        while(equal(mpp, curr_mpp)) {
            if(ans>j-i) {
                ii=i, jj=j;
                ans=j-i;
            }
            if(s[i]>='a' and s[i]<='z') curr_mpp[s[i++]-97]--;
            else curr_mpp[s[i++]-39]--;
        }
    }
    if(ii==0 and jj==0) return "-1";
    return s.substr(ii, jj-ii);
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s, p;
        cin >> s >> p;
        cout<<smallestWindow(s, p)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/