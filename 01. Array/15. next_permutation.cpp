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

// Brute Force :- Find each permutation and return next permutation of the given number

// Optimized Approach (2 pointer) This is 100% faster in C++
void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    int i=n-2; // 'i' will give the index which is one smaller then the first pick element in the array from right end.
    while(i>=0 && nums[i]>=nums[i+1]) {
        i--;
    }
    int j=i; // 'j' will give the index which is just larger then element at 'i' index.
    if(i>=0) { // if i==-1 we don't have an elemnet there. This indicates that the given array is sorted in reverse order.
        while(j<n-1 && nums[j+1]>nums[i]) {
            j++;
        }

        // Swapping i with j to get just next permutation.
        swap(nums[j], nums[i]);
    }

    // We need to swap the elements in the array between i and n-1 elements.
    i++;
    j=n-1;
    while(i<j) {
        swap(nums[i], nums[j]);
        i++, j--;
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) {
            cin>>nums[i];
        }

        nextPermutation(nums);

        for(int i=0; i<n; i++) {
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
