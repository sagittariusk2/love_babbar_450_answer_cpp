/*
    Question link :- (https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1)
    Question :- Find row with maximum no. of 1's
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
	    // code here
	    int i=0, j=m-1, ans_index=0, ans_max=0;
	    while(i<n && j>=0) {
	        if(arr[i][j]==1) j--;
	        else i++;
	        if(ans_max<m-j-1) {
	            ans_max=m-j-1;
	            ans_index=i;
	        }
	    }
	    if(ans_max==0) return -1;
	    return ans_index;
	}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<vector<int>> arr(n, vector<int>(m));

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>arr[i][j];

        cout<<rowWithMax1s(arr, n, m)<<"\n";
    }
}

/*
    Time Complexity :- O(m+n)
    Space Complexity :- O(1)
*/
