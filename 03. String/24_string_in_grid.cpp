/*
    Question link :- (https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1#)
    Question :- Find the string in grid

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int x1[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int y1[8]={-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int i, int j, int n, int m) {
    return (!(i<0 or i>=n or j<0 or j>=m));
}

bool solve(string str, int i, int n, int m, vector<vector<char>> &mat, int x, int y, int d) {
    if(valid(x, y, n, m) and str[i]==mat[x][y]) {
        return solve(str, i+1, n, m, mat, x+x1[d], y+y1[d], d);
    }
    if(i>=str.length()) return true;
    return false;
}

vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	vector<vector<int>> ans;
    int n = grid.size(), m = grid[0].size();
	for(int i=0; i<n; i++) {
	    for(int j=0; j<m; j++) {
	        bool x=false;
            for(int k=0; k<8; k++) {
	            x = x or solve(word, 0, n, m, grid, i, j, k);
	            if(x) {
	                vector<int> v1;
	                v1.push_back(i);
                    v1.push_back(j);
	                ans.push_back(v1);
	                break;
	            }
	        }
	    }
    }
	return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        string str1;
        cin >> n >> m >> str1;
        vector<vector<char>> mat(n, vector<char>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> mat[i][j];
            }
        }
        vector<vector<int>> ans = searchWord(mat, str1);

        for(auto i:ans) {
            for(int j:i) {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n*m)
    Space Complexity :- O(n*m)
*/