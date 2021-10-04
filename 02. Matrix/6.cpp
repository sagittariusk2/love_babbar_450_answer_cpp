/*
    Question link :- (https://practice.geeksforgeeks.org/problems/max-rectangle/1)
    Question :- Maximum size rectangle
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int maxArea(vector<vector<int>> &M, int n, int m) {
        // Your code here
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(M[i][j]) M[i][j] += M[i-1][j];
            }
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++) {
            int left[m], right[m];
            stack<int> s1, s2;
            
            for(int j=0; j<m; j++) {
                while(!s1.empty() and M[i][s1.top()]>=M[i][j])
                    s1.pop();
                left[j] = s1.empty()?0:s1.top()+1;
                s1.push(j);
            }
            
            for(int j=m-1; j>=0; j--) {
                while(!s2.empty() and M[i][s2.top()]>=M[i][j])
                    s2.pop();
                right[j] = s2.empty()?m-1:s2.top()-1;
                s2.push(j);
            }
            
            for(int j=0; j<m; j++) {
                ans = max(ans, (right[j]-left[j]+1)*M[i][j]);
            }
        }
        
        return ans;
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

        cout<<maxArea(arr, n, m)<<"\n";
    }
}

/*
    Time Complexity :- O(m*n)
    Space Complexity :- O(m)
*/
