/*
    Question link :- (https://practice.geeksforgeeks.org/problems/edit-distance3702/1)
    Question :- Edit Distance
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int editDistance(string s, string t) {
    int n = s.length(), m = t.length();

    if(m>n) return editDistance(t, s);

    int dp[2][m+1];
    for(int i=0; i<=m; i++) {
        dp[0][i] = i;
    }

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(j==0) dp[1][j] = i;
            else {
                // if both char are equal then no need to add any operation.
                if(s[i-1]==t[j-1]) dp[1][j] = dp[0][j-1];

                // Add a operation if both are unequal
                else {
                    dp[1][j] = min(dp[0][j], dp[1][j-1]);
                    dp[1][j] = min(dp[1][j], dp[0][j-1]);
                    dp[1][j] ++;
                }
            }
        }

        // Copy value to upper part from lower part.
        for(int j=0; j<=m; j++) {
            dp[0][j] = dp[1][j];
        }
    }

    return dp[0][m];
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str1, str2;
        cin >> str1 >> str2;

        int ans = editDistance(str1, str2);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(min(m, n))
*/