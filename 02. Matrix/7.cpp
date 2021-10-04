/*
    Question link :- (https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/)
    Question :- Find a specific pair in Matrix
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int specificPair(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(m+1));

    for(int i=n; i>=0; i--) {
        for(int j=m; j>=0; j--) {
            if(i==n || j==m) {
                dp[i][j].first=LLONG_MIN;
                dp[i][j].second=LLONG_MAX;
            } else {
                dp[i][j].first = max(dp[i+1][j].first, dp[i][j+1].first);
                dp[i][j].first = max(dp[i][j].first, matrix[i][j]);
                dp[i][j].second = min(dp[i+1][j].second, dp[i][j+1].second);
                dp[i][j].second = min(dp[i][j].second, matrix[i][j]);
            }
        }
    }

    int ans=LLONG_MIN;

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-1; j++) {
            ans = max(ans, dp[i+1][j+1].first-matrix[i][j]);
        }
    }

    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<vector<int>> arr(n, vector<int>(m));

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>arr[i][j];

        cout<<specificPair(arr)<<"\n";
    }
}

/*
    Time Complexity :- O(m*n)
    Space Complexity :- O(m*n)
*/
