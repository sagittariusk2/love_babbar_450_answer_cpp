/*
    Question link :- (https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/)
    Question :- Count of number of given string in 2D character array
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool valid(int i, int j, int n, int m) {
    return (!(i<0 or i>=n or j<0 or j>=m));
}

bool solve(string str, int i, int n, int m, vector<vector<char>> &mat, int x, int y, vector<vector<bool>> vis) {
    if(valid(x, y, n, m) and str[i]==mat[x][y] and !vis[x][y]) {
        vis[x][y]=true;
        bool a1 = solve(str, i+1, n, m, mat, x+1, y, vis);
        bool a2 = solve(str, i+1, n, m, mat, x, y+1, vis);
        bool a3 = solve(str, i+1, n, m, mat, x, y-1, vis);
        bool a4 = solve(str, i+1, n, m, mat, x-1, y, vis);
        return (a1 or a2 or a3 or a4);
    }
    if(i>=str.length()) return true;
    return false;
}

int countString(string s, vector<vector<char>> &mat) {
    int n=mat.size(), m=mat[0].size(), ans=0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans += solve(s, 0, n, m, mat, i, j, vis);
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        string str1;
        cin >> n >> m >> str1;
        vector<vector<char>> mat(n, vector<char>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> mat[i][j];
            }
        }
        int ans = countString(str1, mat);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n*m)
    Space Complexity :- O(n*m)
*/