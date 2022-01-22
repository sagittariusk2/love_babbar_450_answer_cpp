/**
 * @file 19_bishu_and_soldiers
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-22
 * @time 01:01
 * @link https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/
 * @copyright Copyright (c) 2022
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n;
	cin >> n;
	vector<int> nums(n), sum(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	sum[0] = nums[0];
	for(int i=1; i<n; i++) {
		sum[i] = nums[i] + sum[i-1];
	}

	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		int i = upper_bound(nums.begin(), nums.end(), x)-nums.begin();
		
		cout << i << " " << ((i-1==-1)?0:sum[i-1]) << endl;
	}
}