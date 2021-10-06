/*
    Question link :- (https://practice.geeksforgeeks.org/problems/sorted-matrix/0)
    Question :- Print elements in sorted order using row-column wise sorted matrix
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> v1;
        for(auto i:Mat) {
            for(auto j:i) {
                v1.push_back(j);
            }
        }
        sort(v1.begin(), v1.end());
        
        int k=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                Mat[i][j]=v1[k++];
            }
        }
        return Mat;
    }

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<vector<int>> arr(n, vector<int>(n));

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];

        sortedMatrix(n, arr);

        for(auto i:arr) {
            for(auto j:i)
                cout<<j<<" ";
            cout<<"\n";
        }
    }
}

/*
    Time Complexity :- O(n^2longn)
    Space Complexity :- O(n^2)
*/
