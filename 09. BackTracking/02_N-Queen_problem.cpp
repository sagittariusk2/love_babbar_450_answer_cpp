/**
 * @file 02_N-Queen_problem
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-21
 * @time 00:56
 * @link https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1/#
 * @copyright Copyright (c) 2022
 */


// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<vector<int>> ans;

    bool valid(int i, int j, int n) {
        return (i>=0 and j>=0 and i<n and j<n);
    }

    bool canKeep(vector<vector<int>> &pos, int i, int j, int n) {
        for(int k=0; k<i; k++) {
            if(pos[k][j]) return false;
        }
        int a=i, b=j;
        while(valid(a, b, n)) {
            if(pos[a--][b--]) return false;
        }
        a=i, b=j;
        while(valid(a, b, n)) {
            if(pos[a--][b++]) return false;
        }
        return true;
    }

    void solve(vector<vector<int>> pos, int i, int n, vector<int> &v1) {
        if(i==n) {
            ans.push_back(v1);
            return;
        }
        for(int j=0; j<n; j++) {
            if(canKeep(pos, i, j, n)) {
                v1.push_back(j+1);
                pos[i][j] = 1;
                solve(pos, i+1, n, v1);
                pos[i][j] = 0;
                v1.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> pos(n, vector<int>(n, 0));
        vector<int> v1;
        solve(pos, 0, n, v1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends