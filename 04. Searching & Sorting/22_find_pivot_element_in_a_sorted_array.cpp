/**
 * @file 22_find_pivot_element_in_a_sorted_array
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-22
 * @time 22:30
 * @link https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        while(s<e) {
            int mid = (s+e)/2;
            if(nums[mid]>nums[e]) {
                s=mid+1;
            } else {
                e = mid;
            }
        }
        return nums[s];
    }
};

signed main() {
    //code here
}