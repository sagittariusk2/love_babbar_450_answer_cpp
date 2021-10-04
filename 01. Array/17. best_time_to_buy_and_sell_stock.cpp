/* 
    Question Link :- (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
    Best Time to Buy and Sell Stock
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

// Brute Force :- Time complexity :- O(n^2), Space Complexity :- O(1)

// Optimized approach

int maxProfit(vector<int>& prices) {
    int ans=0, mini=prices[0];
    for(auto i:prices) {
        mini = min(mini, i);
        ans = max(ans, i-mini);
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> prices(n);
        for(int i=0; i<n; i++) {
            cin>>prices[i];
        }

        cout<<maxProfit(prices)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
