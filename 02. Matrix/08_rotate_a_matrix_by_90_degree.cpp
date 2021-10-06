/*
    Question link :- (https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/)
    Question :- Rotate a matrix by 90 degree in clockwise direction without using any extra space
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void rotateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<vector<int>> arr(n, vector<int>(n));

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];

        rotateMatrix(arr);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}

/*
    Time Complexity :- O(n*n)
    Space Complexity :- O(1)
*/