/**
 * @file 31_minimum_time_to_required_to_rot_all_the_oranges
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 13:21
 * @link https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#
 * @copyright Copyright (c) 2022
 */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    
    bool valid(int i, int j, int n, int m) {
        return (i>=0 and j>=0 and i<n and j<m);
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<vector<int>> points;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==2) {
                    ans[i][j]=0;
                    points.push({i, j});
                }
                if(grid[i][j]==0) ans[i][j]=0;
            }
        }
        vector<int> x2({0, 0, 1, -1});
        vector<int> y2({-1, 1, 0, 0});
        int c=0;
        while(!points.empty()) {
            c++;
            vector<vector<int>> qu;
            while(!points.empty()) {
                int i=points.front()[0], j=points.front()[1];
                points.pop();
                for(int k=0; k<4; k++) {
                    if(valid(i+x2[k], j+y2[k], n, m) and ans[i+x2[k]][j+y2[k]]==INT_MAX and grid[i+x2[k]][j+y2[k]]==1) {
                        ans[i+x2[k]][j+y2[k]]=c;
                        qu.push_back({i+x2[k], j+y2[k]});
                    }
                }
            }
            for(auto i:qu) {
                points.push(i);
            }
        }
        c=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(ans[i][j]==INT_MAX) return -1;
                else {
                    c = max(c, ans[i][j]);
                }
            }
        }
        return c;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends