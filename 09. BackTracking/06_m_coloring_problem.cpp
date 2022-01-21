/**
 * @file 06_m_coloring_problem
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-18
 * @time 18:13
 * @link https://practice.geeksforgeeks.org/problems/m-coloring-problem/0
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool canInsert(vector<int>&v1, int i, int V, bool graph[101][101], int n) {
    for(int j=0; j<n; j++) {
        if(graph[V][j] and v1[j]==i) return false;
    }
    return true;
}

bool found=false;

void solve(bool graph[101][101], int V, vector<int> v1, int n, int m) {
    if(V==n) found = true;
    if(found) return;
    for(int i=1; i<=m; i++) {
        if(canInsert(v1, i, V, graph, n)) {
            v1[V]=i;
            solve(graph, V+1, v1, n, m);
        }
    }
}

bool graphColoring(bool graph[101][101], int m, int V) {
    found = false;
    vector<int> v1(V, -1);
    solve(graph, 0, v1, V, m);
    return found;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends