/*
    Question link :- (https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)
    Question :- Longest Common Subsequence
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int lcs(int x, int y, string s1, string s2) {
    if(x<y) return lcs(y, x, s2, s1);
    vector<vector<int>> dp(2, vector<int>(y+1, 0));
    for(int i=1; i<=x; i++) {
        for(int j=0; j<=y; j++) {
            if(j==0) dp[1][j]=0;
            else {
                if(s1[i-1]==s2[j-1]) dp[1][j]=1+dp[0][j-1];
                else dp[1][j] = max(dp[1][j-1], dp[0][j]);
            }
        }
        for(int j=0; j<=y; j++) {
            dp[0][j]=dp[1][j];
        }
    }

    return dp[1][y];
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str1, str2;
        cin >> str1 >> str2;
        cout << lcs(str1.length(), str2.length(), str1, str2) << "\n";
    }
}

/*
    Time Complexity :- O(n*m)
    Space Complexity :- O(min(n, m))
*/