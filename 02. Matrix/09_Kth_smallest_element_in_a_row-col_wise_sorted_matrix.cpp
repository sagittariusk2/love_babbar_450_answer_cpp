/*
    Question link :- (https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1)
    Question :- Kth smallest element in a row-cpumn wise sorted matrix
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int kthSmallest(vector<vector<int>> &mat, int n, int k) {
    int a = mat[0][0], b = mat[n-1][n-1];
    
    while(a<b) {
        int mid = (a+b)/2, x=0;
        
        for(int i=0; i<n; i++) {
            x += upper_bound(mat[i].begin(), mat[i].end(), mid)-mat[i].begin();
        }
        
        if(x<k) a = mid+1;
        else b = mid;
    }
    return a;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<vector<int>> arr(n, vector<int>(n));

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];

        cout<<kthSmallest(arr, n, k);
    }
}

/*
    Time Complexity :- O(n*logn)
    Space Complexity :- O(1)
*/