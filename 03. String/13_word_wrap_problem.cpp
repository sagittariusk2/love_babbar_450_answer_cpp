/*
    Question link :- (https://practice.geeksforgeeks.org/problems/next-permutation/0)
    Question :- Find next greater number with same set of digits. [Very Very IMP]
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int solveWordWrap(vector<int> arr, int k) {
    int n = arr.size();

    vector<vector<int>> lc(n+1, vector<int>(n+1, -1));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) lc[i][j] = arr[j-1];
            else {
                lc[i][j] = lc[i][j-1]+arr[j-1]+1;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(lc[i][j]!=-1)
                lc[i][j] = (k-lc[i][j])*(k-lc[i][j]);
        }
    }

    int c[n+1];
    c[0]=0;
    for(int j=1; j<=n; j++) {
        int x = INT_MAX;
        for(int i=1; i<=j; i++) {
            x = min(x, c[i-1]+lc[i][j]);
        }
        c[j] = x;
    }

    return c[n];
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }

        int ans = solveWordWrap(arr, k);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(n)
*/