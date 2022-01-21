/**
 * @file 17_print_all_possible_path_from_top-left_to_bottom-right_of_a_mXn_matrix
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-19
 * @time 22:36
 * @link https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> solve(int n, int m, vector<vector<int>> &nums, vector<vector<vector<vector<int>>>> &dp) {
    if(!dp[n][m].empty()) return dp[n][m];
    if(n==0 and m==0) {
        vector<vector<int>> v1;
        v1.push_back({nums[n][m]});
        return dp[n][m] = v1;
    }
    vector<vector<int>> v1;
    vector<vector<int>> v2;
    if(n!=0)
        v1 = solve(n-1, m, nums, dp);
    if(m!=0)
        v2 = solve(n, m-1, nums, dp);
    vector<vector<int>> ans;
    for(auto i:v1) {
        i.push_back(nums[n][m]);
        ans.push_back(i);
    }
    for(auto i:v2) {
        i.push_back(nums[n][m]);
        ans.push_back(i);
    }
    return dp[n][m] = ans;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> nums[i][j];
        }
    }
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m));
    vector<vector<int>> ans = solve(n-1, m-1, nums, dp);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}