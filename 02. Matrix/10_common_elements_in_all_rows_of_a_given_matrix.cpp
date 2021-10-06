/*
    Question link :- (https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/)
    Question :- Common elements in all rows of a given matrix
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<int> commonElements(vector<vector<int>> &matrix) {
    int n=matrix.size(), m = matrix[0].size();
    unordered_map<int, int> mpp;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0) mpp[matrix[i][j]]++;
            else {
                if(mpp.find(matrix[i][j])!=mpp.end()) {
                    mpp[matrix[i][j]]++;
                }
            }
        }
    }

    vector<int> ans;
    for(auto i:mpp) {
        if(i.second==n) ans.push_back(i.first);
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

        vector<int> ans = commonElements(arr);
        for(auto i:ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(mn)
    Space Complexity :- O(m)
*/
