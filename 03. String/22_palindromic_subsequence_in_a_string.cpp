/*
    Question link :- (https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1)
    Question :- Count Palindromic Subsequences
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int dp[1000][1000];

int solve(int i, int j, string &str) {
    if(dp[i][j]!=-1) return dp[i][j];
    if(i<j) {
        if(str[i]==str[j]) {
            return dp[i][j] = (1+(solve(i+1, j, str)%M+solve(i, j-1, str)%M)%M)%M;
        }
        else return dp[i][j] = (solve(i+1, j, str)%M+(solve(i, j-1, str)%M-solve(i+1, j-1, str)%M+M)%M)%M;
    }
    if(i==j) return dp[i][j] = 1;
    return dp[i][j] = 0;
}

int countPS(string str) {
    int n = str.size(), ans=0;
    memset(dp, -1, sizeof(dp));
    return solve(0, n-1, str);
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin >> str;
        cout << countPS(str) << "\n";
    }
}

/*
    Time Complexity :- O(n*n)
    Space Complexity :- O(n*n)
*/