/**
 * @file 27_GIVEN_GRAPH_IS_A_TREE_OR_NOT
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-12
 * @time 10:48
 * @link https://www.geeksforgeeks.org/check-given-graph-tree/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

class Graph {
private:
    int n;
    list<int> *adj;

    bool solve(int root, int parent, bool vis[]) {
        if(vis[root]) return true;
        vis[root]=true;
        bool x = false;
        for(auto it:adj[root]) {
            if(it!=parent) {
                x = x or solve(it, root, vis);
            }
        }
        return x;
    }
public:
    Graph(int n) {
        this->n = n;
        adj = new list<int>[n];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isConnected() {
        bool vis[n]={false};
        queue<int> qu;
        qu.push(0);
        while(!qu.empty()) {
            for(auto it:adj[qu.front()]) {
                if(!vis[it]) qu.push(it);
                vis[it] = true;
            }
            qu.pop();
        }

        for(int i=0; i<n; i++) {
            if(!vis[i]) return false;
        }
        return true;
    }

    bool isCyclic() {
        bool vis[n] = {false};
        bool ans = false;
        for(int i=0; i<n; i++) {
            if(!vis[i]) ans = ans or solve(0, -1, vis);
        }
        return ans;
    }

    bool isTree() {
        return !isCyclic() and isConnected();
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        graph.addEdge(x, y);
    }

    cout << graph.isTree() << endl;
}