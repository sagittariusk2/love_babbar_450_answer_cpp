/**
 * @file 11_find_shortest_safe_route_in_a_path_with_landmines
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-20
 * @time 14:58
 * @link https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

bool valid(int i, int j, int n, int m) {
    return (i>=0 and j>=0 and i<n and j<m);
}

int solve(int i, int j, int n, int m, vector<vector<int>> &mines, vector<vector<bool>> vis) {
    if(j==m-1) return 0;
    if(valid(i, j, n, m) and mines[i][j] and !vis[i][j]) {
        vis[i][j] = true;
        int a = solve(i+1, j, n, m, mines, vis);
        int b = solve(i, j+1, n, m, mines, vis);
        int c = solve(i-1, j, n, m, mines, vis);
        int d = solve(i, j-1, n, m, mines, vis);
        int x = min(min(a, b), min(c, d));
        if(x==INT_MAX) return x;
        return x+1;
    }
    return INT_MAX;
}

int shortest_route(vector<vector<int>> &mines) {
    int n = mines.size();
    int m = mines[0].size();
    vector<vector<int>> modified_mines(n, vector<int>(m, 1));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mines[i][j]==0) {
                modified_mines[i][j] = 0;
                if(valid(i+1, j, n, m))
                    modified_mines[i+1][j] = 0;
                if(valid(i, j+1, n, m))
                    modified_mines[i][j+1] = 0;
                if(valid(i, j-1, n, m))
                    modified_mines[i][j-1] = 0;
                if(valid(i-1, j, n, m))
                    modified_mines[i-1][j] = 0;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = INT_MAX;
    for(int i=0; i<n; i++) {
        if(modified_mines[i][0]==1) {
            ans = min(ans, solve(i, 0, n, m, modified_mines, vis));
        }
    }
    return (ans==INT_MAX)?-1:ans;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mines(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mines[i][j];
        }
    }

    cout << shortest_route(mines) << endl;
}