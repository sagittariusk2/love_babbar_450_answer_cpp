/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/inversion-of-array/0)
    Count Inversion
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

// Brute Force :- Time complexity :- O(n^2), Space Complexity :- O(1)

// BIT approach

// Merge sort approach :- Calculate inversion while sorting

int merging(int nums[], int start, int mid, int end) {
    //Initializing the pointers
    int i=start, j=mid+1, ans=0;

    // Initializing the temporary array
    vector<int> temp;
    while(i<=mid && j<=end) {
        if(nums[i]<=nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);

            // Calculating answer from the logic that how many elements are right to 'i' to 'mid'.
            ans += (mid-i+1);
        }
    }

    // Moving remaining elements to thr temporary array
    while(i<=mid) {
        temp.push_back(nums[i++]);
    }
    while(j<=end) {
        temp.push_back(nums[j++]);
    }

    // Updating the original array.
    j=0;
    for(i=start; i<=end; i++) {
        nums[i]=temp[j++];
    }
    return ans;
}

int solve(int nums[], int start, int end) {
    if(start<end) {
        // Dividing the array in 2 part.
        int mid = (start+end)/2;

        // Calling the same function for the left part and right part
        int x = solve(nums, start, mid);
        int y = solve(nums, mid+1, end);

        // Merge the two part
        int z = merging(nums, start, mid, end);
        return x+y+z;
    }
    return 0;
}

int inversionCount(int arr[], int n) {
    // Your Code Here
    return solve(arr, 0, n-1);
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

        cout<<inversionCount(nums, n)<<"\n";
    }
}

/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(n)
*/
