/**
 * @file 21_kth_smallest_number_again
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-22
 * @time 22:34
 * @link https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> nums(n);
        for(int i=0; i<n; i++) {
            cin >> nums[i].first >> nums[i].second;
        }
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> v2;
        int s = nums[0].first, e=nums[0].second;
        for(int i=1; i<n; i++) {
            if(nums[i].first<=e) {
                e = max(e, nums[i].second);
            } else {
                v2.emplace_back(s, e);
                s = nums[i].first;
                e = nums[i].second;
            }
        }
        v2.emplace_back(s, e);
        n = v2.size();
        vector<int> v1(n);
        for(int i=0; i<n; i++) {
            if(i==0) {
                v1[i]=v2[i].second-v2[i].first+1;
            } else {
                v1[i] = v1[i-1] + (v2[i].second-v2[i].first+1);
            }
        }
        while(q--) {
            int k;
            cin >> k;
            int i = lower_bound(v1.begin(), v1.end(), k)-v1.begin();
            if(i==n) cout << -1 << endl;
            else {
                int x = (i==0)?0:v1[i-1];
                cout << v2[i].first+k-x-1 << endl;
            }
        }
    }
}