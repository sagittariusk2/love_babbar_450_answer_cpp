/**
 * @file 16_longest_possible_route_in_a_matrix_with_hurdles
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-19
 * @time 23:28
 * @link https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

bool validPoints(int i, int j, int n, int m) {
    return (i>=0 and j>=0 and i<n and j<m);
}

int findLongestRoute(vector<vector<int>> &grid, int sx, int sy, int dx, int dy, vector<vector<bool>> vis) {
    if(validPoints(sx, sy, grid.size(), grid[0].size()) and grid[sx][sy] and !vis[sx][sy]) {
        vis[sx][sy]=true;
        if(sx==dx and sy==dy) return 0;
        int a = findLongestRoute(grid, sx+1, sy, dx, dy, vis);
        int b = findLongestRoute(grid, sx, sy+1, dx, dy, vis);
        int c = findLongestRoute(grid, sx-1, sy, dx, dy, vis);
        int d = findLongestRoute(grid, sx, sy-1, dx, dy, vis);
        int mx = max(max(a, b), max(c, d));
        return mx+1;
    }
    return INT_MIN;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    cout << findLongestRoute(grid, sx, sy, dx, dy, vis);
}