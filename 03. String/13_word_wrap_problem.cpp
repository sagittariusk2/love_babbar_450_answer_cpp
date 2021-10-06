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

    vector<vector<int>> lc(n, vector<int>(n, -1));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            
        }
    }
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
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/