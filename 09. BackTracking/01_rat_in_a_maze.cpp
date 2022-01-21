/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<string> ans;

bool valid(int i, int j, int n) {
    if(i<0 or i>=n or j<0 or j>=n) return false;
    return true;
}

void solve(vector<vector<int>> &m, int i, int j, int n, string s, vector<vector<bool>> visited) {
    if(i==n-1 && j==n-1 && m[i][j]==1) {
        ans.push_back(s);
    }
    else if(valid(i, j, n) && m[i][j]==1 && !visited[i][j]) {
        visited[i][j]=true;
        solve(m, i+1, j, n, s+'D', visited);
        solve(m, i, j-1, n, s+'L', visited);
        solve(m, i, j+1, n, s+'R', visited);
        solve(m, i-1, j, n, s+'U', visited);
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    solve(m, 0, 0, n, "", visited);
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> m(n, vector<int>(n, 0));

        // Value can be '0' or '1'
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin>>m[i][j];
            }
        }

        vector<string> paths = findPath(m, n);

        for(auto i:paths) 
            cout<<i<<" ";
        cout<<"\n";
    }
}

/*
    Time Complexity :- O((n^2)^4)
    Space Complexity :- O(length_of_path * number_of_path)
*/
