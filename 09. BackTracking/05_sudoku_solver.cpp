/**
 * @file 05_sudoku_solver
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-16
 * @time 18:10
 * @link https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution {
    public:
    //Function to find a solved Sudoku.
    
    void next_pointer(int &x, int &y) {
        if(y==8) x++, y=0;
        else y++;
    }
    
    bool ans=false;
    vector<int> ans2;
    
    bool safeInsert(int x, int y, int k, vector<vector<int>> &grid) {
        for(int i=0; i<9; i++) {
            if(grid[i][y]==k) return false;
        }
        for(int i=0; i<9; i++) {
            if(grid[x][i]==k) return false;
        }
        x /= 3;
        y /= 3;
        x = (3*x), y = 3*y;
        for(int i=x; i<x+3; i++) {
            for(int j=y; j<y+3; j++) {
                if(grid[i][j]==k) return false;
            }
        }
        return true;
    }
    
    void solve(int x, int y, vector<vector<int>> grid) {
        if(x==9 and y==0) {
            ans = true;
            for(int i=0; i<9; i++) {
                for(int j=0; j<9; j++) {
                    ans2.push_back(grid[i][j]);
                }
            }
        }
        if(!ans) {
            if(grid[x][y]==0) {
                for(int i=1; i<=9; i++) {
                    if(safeInsert(x, y, i, grid)) {
                        int x1=x, y1=y;
                        grid[x][y] = i;
                        next_pointer(x1, y1);
                        solve(x1, y1, grid);
                    }
                }
            } else {
                int x1=x, y1=y;
                next_pointer(x1, y1);
                solve(x1, y1, grid);
            }
        }
    }
    bool SolveSudoku(int grid[N][N]) {
        vector<vector<int>> v1(9, vector<int>(9, 0));
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                v1[i][j] = grid[i][j];
            }
        }
        solve(0, 0, v1);
        return ans;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) {
        for(auto i:ans2) {
            cout << i << " ";
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends