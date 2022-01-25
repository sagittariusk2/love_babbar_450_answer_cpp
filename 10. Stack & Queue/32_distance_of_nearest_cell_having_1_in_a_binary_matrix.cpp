/**
 * @file 32_distance_of_nearest_cell_having_1_in_a_binary_matrix
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 12:52
 * @link https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#
 * @copyright Copyright (c) 2022
 */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool valid(int i, int j, int n, int m) {
        return (i>=0 and j>=0 and i<n and j<m);
    }

    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid) {
	    int n=grid.size();
	    int m = grid[0].size();
	    queue<vector<int>> points;
	    vector<vector<int>> ans(n, vector<int>(m, -1));
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            if(grid[i][j]) {
	                points.push({i, j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    vector<int> x2({0, 0, 1, -1});
	    vector<int> y2({-1, 1, 0, 0});
	    int c=1;
	    while(!points.empty()) {
	        vector<vector<int>> qu;
	        while(!points.empty()) {
	            int i=points.front()[0], j=points.front()[1];
	           // ans[i][j]=c;
	            points.pop();
	            for(int k=0; k<4; k++) {
	                if(valid(i+x2[k], j+y2[k], n, m) and ans[i+x2[k]][j+y2[k]]==-1) {
	                    ans[i+x2[k]][j+y2[k]]=c;
	                    qu.push_back({i+x2[k], j+y2[k]});
	                }
	            }
	        }
	        for(auto i:qu) {
	            points.push(i);
	        }
	       // points=qu;
	        c++;
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends