/*
    Question link :- (https://leetcode.com/problems/shortest-palindrome/)
    Question :- Shortest Palindrome
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<int> pi_function(string str) {
    int n=str.length();
    vector<int> pi(n, 0);
    for(int i=1; i<n; i++) {
        int j=pi[i-1];
        while(j>0 and str[i]!=str[j]) {
            j = pi[j-1];
        }
        if(str[i]==str[j]) j++;
        pi[i] = j;
    }
    return pi;
}

string shortestPalindrome(string s) {
    if(s.length()==0) return s;
    string ans=s;
    reverse(ans.begin(), ans.end());
    vector<int> pi = pi_function(s+'#'+ans);
    int x = pi[pi.size()-1];
    string c = s.substr(x);
    reverse(c.begin(), c.end());
    return c+s;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin >> str;
        cout<<shortestPalindrome(str)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/