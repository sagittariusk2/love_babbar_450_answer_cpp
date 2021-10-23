/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1)
    Find All Four Sum Numbers
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int sum) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-3; i++) {
            if(i==0 or (i!=0 and arr[i]!=arr[i-1])) {
                for(int j=i+1; j<n-2; j++) {
                    if(j==i+1 or (j!=i+1 and arr[j]!=arr[j-1])) {
                        int k=j+1, l=n-1;
                        while(k<l) {
                            int t = arr[i]+arr[j]+arr[k]+arr[l];
                            if(t>sum) {
                                l--;
                            } else if(t<sum) {
                                k++;
                            } else {
                                vector<int> x;
                                x.push_back(arr[i]);
                                x.push_back(arr[j]);
                                x.push_back(arr[k]);
                                x.push_back(arr[l]);
                                ans.push_back(x);
                                while(k+1<n and arr[k]==arr[k+1]) k++;
                                while(k-1>j and arr[l]==arr[l-1]) l--;
                                k++;
                                l--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}

/*
    Time complexity :- O(n^3)
    Sspace Complexity :- O(n^2)
*/