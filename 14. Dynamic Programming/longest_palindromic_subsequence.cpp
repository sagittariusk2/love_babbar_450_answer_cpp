#include<bits/stdc++.h>

using namespace std;

int lps(string str, int i, int j, vector<vector<int>> &dp) {
    if(dp[i][j]==-1) {
        int ans;
        if(i==j) ans=1;
        else {
            if(str[i]==str[j]) ans = 2+lps(str, i-1, j+1, dp);
            else ans = max(lps(str, i+1, j, dp), lps(str, i, j-1, dp));
        }
        dp[i][j]=ans;
        return ans;
    }
    return dp[i][j];
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int n=str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        lps(str, 0, n-1, dp);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}