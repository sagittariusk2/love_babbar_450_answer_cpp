/* 
    Question Link :- (https://leetcode.com/problems/next-permutation/)
    Next Permutation
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

// Optimized Approach linear traversal
long long maxSubarraySum(int arr[], int n){

    // Kadane's Algorithm

    long long max_sum=arr[0], curr_sum=arr[0]; 

    for(int i=1; i<n; i++) {
        if(curr_sum+arr[i]>arr[i]) {
            curr_sum += arr[i];
        } else {
            curr_sum = arr[i];
        }
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int nums[n];
        for(int i=0; i<n; i++) {
            cin>>nums[i];
        }

        cout<<maxSubarraySum(nums, n)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
