/**
 * @file 15_find_if_there_is_a_path_of_more_than_k_length_from_a_source
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-19
 * @time 23:50
 * @link https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

bool solve(int i, vector<bool> vis, int n, vector<vector<int>> &edges, int k, int len) {
    if(len>=k) return true;
    if(!vis[i]) {
        vis[i] = true;
        bool x = false;
        for(int j=0; j<n; j++) {
            if(edges[i][j]!=-1) {
                x = x or solve(j, vis, n, edges, k, len+edges[i][j]);
            }
        }
        return x;
    }
    return false;
}

bool isAPpath(vector<vector<int>> &edges, int n, int k) {
    vector<bool> vis(n, false);
    bool y = false;
    for(int i=0; i<n; i++) {
        y = y or solve(i, vis, n, edges, k, 0);
    }
    return y;
}

signed main() {
    int n;
    cin >> n;
    int edge;
    cin >> edge;
    vector<vector<int>> edges(n, vector<int>(n, -1));
    for(int i=0; i<edge; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b] = c;
        edges[b][a] = c;
    }

    int k;
    cin >> k;

    // solve for each node using recurssion

    cout << isAPpath(edges, n, k) << endl;
}