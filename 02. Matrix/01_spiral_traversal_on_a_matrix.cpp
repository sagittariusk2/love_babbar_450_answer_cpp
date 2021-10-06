/*
    Question link :- (https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0)
    Question :- Spiral traversal on a Matrix
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void solve(vector<int> &ans, vector<vector<int>> matrix, int start, int top, int bottom) {
    if(start>top || start>bottom) return;
    for(int i=start; i<=top; i++) {
        ans.push_back(matrix[start][i]);
    }
    for(int i=start+1; i<=bottom; i++) {
        ans.push_back(matrix[i][top]);
    }
    if(start!=bottom) {
        for(int i=top-1; i>=start; i--) {
            ans.push_back(matrix[bottom][i]);
        }
    }
    if(start!=top) {
        for(int i=bottom-1; i>start; i--) {
            ans.push_back(matrix[i][start]);
        }
    }
    solve(ans, matrix, start+1, top-1, bottom-1);
}

vector<int> spirallyTraverse(vector<vector<int>> matrix) {
    int n=matrix.size(), m=matrix[0].size();
    vector<int> ans;
    solve(ans, matrix, 0, m-1, n-1);
    return ans;
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

        vector<int> ans=spirallyTraverse(arr);

        for(auto i:ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n*m)
    Space Complexity :- O(n*m)
*/
