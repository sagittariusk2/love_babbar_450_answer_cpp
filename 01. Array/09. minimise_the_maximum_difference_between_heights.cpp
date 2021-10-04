/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1)
    Minimise the maximum difference between heights [V.IMP]
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

class Solution {
    public:
    int getMinDiff(int arr[], int n, int k) {

        // v1 will contain all possible heights
        vector<pair<int, int>> v1;

        for(int i=0; i<n; i++) {
            if(arr[i]-k>=0) // Neglecting negative heights
                v1.push_back({arr[i]-k,i});
            v1.push_back({arr[i]+k,i});
        }

        // Sort it.
        sort(v1.begin(), v1.end());

        int start=0, end=0, s=v1.size(), min_diff=INT_MAX, curr_diff;
        unordered_map<int, int> mpp;

        while(end<s) {
            // Make size of map to 'n'
            while(end<s && mpp.size()!=n) {
                mpp[v1[end++].second]++;
            }
            while(start<end && mpp.size()==n) {
                curr_diff = v1[end-1].first - v1[start].first;
                min_diff = min(min_diff, curr_diff);
                mpp[v1[start++].second]--;
                if(mpp[v1[start-1].second] == 0)
                    mpp.erase(v1[start-1].second);
            }
        }
        return min_diff;
    }
};

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
