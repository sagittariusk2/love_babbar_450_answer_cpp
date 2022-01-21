/**
 * @file 09_the_knights_tour_problem
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-20
 * @time 01:14
 * @link https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

bool validPoints(int i, int j, int n) {
    return (i>=0 and j>=0 and i<n and j<n);
}

int x2[]{2, 1, -1, -2, -2, -1, 1, 2};
int y2[]{1, 2, 2, 1, -1, -2, -2, -1};

vector<vector<int>> ans1;
bool ans2=false;

bool solve(int i, int j, int x, vector<vector<int>> vis) {
    // cout << i << " " << j << endl;
    if(!ans2) {
    if(x==(vis.size()*vis.size())) {
        ans1 = vis;
        ans2= true;
        return true;
    }
    if(validPoints(i, j, vis.size()) and vis[i][j]==-1) {
        vis[i][j]=x;
        bool y = false;
        for(int k=0; k<8; k++) {
            y = y or solve(i+x2[k], j+y2[k], x+1, vis);
        }
        return y;
    }
    return false;
    }
    return true;
}

void findPath(int n) {
    vector<vector<int>> vis(n, vector<int>(n, -1));
    if(solve(0, 0, 0, vis)) {
        for(auto i:ans1) {
            for(auto j:i) {
                cout << j << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Not possible to cover all points\n";
    }
}

signed main() {
    int n;
    cin >> n;
    findPath(n);
}