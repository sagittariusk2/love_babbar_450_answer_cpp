/*
    Question link :- (https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#)
    Question :- Longest Repeating Subsequence
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int LongestRepeatingSubsequence(string str){
	int n = str.length();
    int dp[n+1][n+1], ans=0;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
            if(i==0 || j==0 || i==j) dp[i][j]=0;
		    else {
	            if(str[i-1]==str[j-1]) dp[i][j]=dp[i-1][j-1]+1;
	            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
		    }
            ans=max(ans, dp[i][j]);
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
        cout<<LongestRepeatingSubsequence(s)<<"\n";
    }
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(n^2)
*/
