/*
    Question link :- (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
    Question :- Maximum profit by buying and selling a share atmost twice
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int max_profit(vector<int> &arr) {
    int n = arr.size();
    int max_pro=arr[n-1];
    vector<int> profit(n, 0);

    for(int i=n-2; i>=0; i--) {
        max_pro=max(max_pro, arr[i]);
        profit[i]=max(profit[i+1], max_pro-arr[i]);
    }

    int min_pro=arr[0];

    for(int i=1; i<n; i++) {
        min_pro=min(min_pro, arr[i]);
        profit[i] = max(profit[i-1], profit[i]+arr[i]-min_pro);
    }

    return profit[n-1];
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<max_profit(arr)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
