/*
    Question link :- (https://leetcode.com/problems/search-a-2d-matrix/)
    Question :- Search a 2D Matrix
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        
        int i=0, j=n-1;
        while(i<=j) {
            int mid=(i+j)/2;
            if(target<matrix[mid][0]) {
                j=mid-1;
            } else if(target>matrix[mid][m-1]) {
                i=mid+1;
            } else {
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            }
        }
        return false;
    }

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m, target;
        cin>>n>>m>>target;

        vector<vector<int>> arr(n, vector<int>(m));

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>arr[i][j];

        cout<<searchMatrix(arr, target)<<"\n";
    }
}

/*
    Time Complexity :- O(logn*logm)
    Space Complexity :- O(1)
*/
