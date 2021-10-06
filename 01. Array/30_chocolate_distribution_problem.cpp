/*
    Question link :- (https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0)
    Question :- Chocolate Distribution problem
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int findMinDiff(vector<int> a, int n, int m) {
    sort(a.begin(), a.end());
    int ans=LONG_MAX;
    for(int i=0; i<=n-m; i++) {
        ans = min(ans, a[i+m-1]-a[i]);
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<int> arr(n);

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<findMinDiff(arr, n, m)<<"\n";
    }
}

/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(1)
*/
