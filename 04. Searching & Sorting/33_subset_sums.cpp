/**
 * @file 33_subset_sums
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-13
 * @time 11:22
 * @link https://www.spoj.com/problems/SUBSUMS/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> getDP(vector<int> &nums) {
    int n = nums.size();
    int m = 1<<n;
    vector<int> dp(m, 0);
    for(int i=1; i<m; i++) {
        int x = log2(i);
        dp[i] = nums[x]+dp[i&((1<<x)-1)];
    }
    sort(dp.begin(), dp.end());
    return dp;
}

signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums1, nums2;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(nums1.size()!=n/2) nums1.push_back(x);
        else nums2.push_back(x);
    }
    int ans1 = 0, ans2 = 0;
    vector<int> dp1 = getDP(nums1);
    vector<int> dp2 = getDP(nums2);

    for(int i=0; i<dp1.size(); i++) {
        int x1 = a-dp1[i]-1;
        ans1 += dp2.end()-upper_bound(dp2.begin(), dp2.end(), x1);
        ans2 += dp2.end()-upper_bound(dp2.begin(), dp2.end(), b-dp1[i]);
    }

    cout << ans1-ans2 << endl;
}