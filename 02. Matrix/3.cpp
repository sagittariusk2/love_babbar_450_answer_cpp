/*
    Question link :- (https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1)
    Question :- Find median in a row wise sorted matrix
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int median(vector<vector<int>> &matrix, int r, int c) {
    int a=INT_MAX, b=INT_MIN;

    for(int i=0; i<r; i++) {
        a=min(a, matrix[i][0]);
        b=max(b, matrix[i][c-1]);
    }

    int y=(r*c)/2+1;
    int x=0;
    while(a<b) {
        int mid=(a+b)/2;
        x=0;
        for(auto i:matrix) {
            x += upper_bound(i.begin(), i.end(), mid)-i.begin();
        }
        if(x<y) a=mid+1;
        else b=mid;
    }
    return a;
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

        cout<<median(arr, n, m)<<"\n";
    }
}

/*
    Time Complexity :- O(m*n)
    Space Complexity :- O(m)
*/