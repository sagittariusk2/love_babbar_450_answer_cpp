/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0)
 * Maximum sum Rectangle
 */

/**
 * ----@sagittarius_k2-----
 * Created by Ritesh Ranjan
 */

#include <bits/stdc++.h>

using namespace std;

#define int long long int

class Solution {
public:
    int maximumSumRectangle(int R, int C, vector<vector<int>>& M) {
        for(int i=1; i<R; i++) {
            for(int j=0; j<C; j++) {
                M[i][j] += M[i-1][j];
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<R; i++) {
            for(int j=i; j<R; j++) {
                int mx, mx2;
                if(i==0) {
                    mx=M[j][0], mx2=M[j][0];
                } else {
                    mx=M[j][0]-M[i-1][0], mx2=M[j][0]-M[i-1][0];
                }
                for(int k=1; k<C; k++) {
                    if(i==0) {
                        mx = max(mx+M[j][k], M[j][k]);
                    } else {
                        mx = max(mx+(M[j][k]-M[i-1][k]), M[j][k]-M[i-1][k]);
                    }
                    mx2 = max(mx, mx2);
                }
                ans = max(mx2, ans);
            }
        }
        return ans;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int r, c;
		cin >> r >> c;
		vector<vector<int>>nums(r, vector<int>(c));
		for(int i = 0; i < r; i++) {
            for(int j=0; j<c; j++) {
                cin >> nums[i][j];
            }
        }
		Solution obj;
		int ans = obj.maximumSumRectangle(r, c, nums);
		cout << ans <<"\n";
	}
	return 0;
}

/**
 * Time Complexity :- O(r*r*c)
 * Space Complexity :- O(r*c)
 */
