/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1)
    Count pairs with given sum
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
/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(1)
*/


// Hash Map Approach
/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/

int getPairsCount(int arr[], int n, int k) {
    int hash_map[1000001]={0};
    for(int i=0; i<n; i++) {
        hash_map[arr[i]]++;
    }

    int ans=0;

    for(int i=1; i<=1000000; i++) {
        int x=0;
        if(k-i>=1 && k-i<=1000000) {
            x = (hash_map[i]*hash_map[k-i]);
            if(k-i==i) x/=2; // Handling duplicates
        }
        ans += x;
    }

    return ans/2;
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

        cout<<getPairsCount(nums, n, x)<<"\n";
    }
}