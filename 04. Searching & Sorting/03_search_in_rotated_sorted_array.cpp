/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#)
    First and last occurrences of x
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int find_pivot(vector<int> &nums) {
    int s=0, e=nums.size()-1;

    while(s!=e) {
        int mid = (s+e)/2;
        if(nums[mid]>nums[e]) s=mid+1;
        else e=mid;
    }

    return s;
}

int solve(vector<int>& nums, int s, int e, int x) {
    if(s<e) {
        int mid = (s+e)/2;
        if(nums[mid]<x) s = mid+1;
        else e = mid;
        return solve(nums, s, e, x);
    }
    if(nums[s]==x) return s;
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivot = find_pivot(nums);
    int x = solve(nums, 0, pivot-1, target);
    int y = solve(nums, pivot, nums.size()-1, target);
    if(x==-1 and y==-1) return -1;
    if(x==-1) return y;
    return x;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;
        vector<int> nums(n);
        for(int i=0; i<n; i++) {
            cin>>nums[i];
        }

        int ans = search(nums, x);
        cout<<ans<<"\n";
    }
}

/*
    Time Complexity :- O(logn)
    Space Complexity :- O(1)
*/
