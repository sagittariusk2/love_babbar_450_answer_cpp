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

// Brute Force :- Time complexity :- O(n^2), Space Complexity :- O(1)

// Binary Search approach

vector<int> find(int arr[], int n , int x ) {
    // Initialize answer with value -1
    vector<int> ans(2, -1);

    // If element is present then update the answer
    if(binary_search(arr, arr+n, x)) {
        // lower_bound of the element
        ans[0]=lower_bound(arr, arr+n, x)-arr;

        // Upper bound of the element
        ans[1] = upper_bound(arr, arr+n, x)-1-arr;
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;
        int nums[n];
        for(int i=0; i<n; i++) {
            cin>>nums[i];
        }

        vector<int> ans = find(nums, n, x);

        for(auto i:ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(logn)
    Space Complexity :- O(1)
*/
