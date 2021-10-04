/*
    Question link :- (https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1)
    Question :- Longest Palindromic Substring
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

string longestPalindrome(string S) {
    int n = S.length(), len=0;
    string ans;
    for(int i=0; i<n; i++) {
        int j=i-1, k=i+1;
        while(j>=0 && k<n && S[j]==S[k]) {
            j--, k++;
        }
        if(len<k-j-1) {
            len = k-j-1;
            ans=S.substr(j+1, len);
        }
    }
    for(int i=0; i<n; i++) {
        int j=i, k=i+1;
        while(j>=0 && k<n && S[j]==S[k]) {
            j--, k++;
        }
        if(len<k-j-1) {
            len = k-j-1;
            ans=S.substr(j+1, len);
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<longestPalindrome(s)<<"\n";
    }
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(1)
*/
