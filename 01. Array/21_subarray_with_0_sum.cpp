/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#)
    Subarray with 0 sum
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

// Hash Map

bool subArrayExists(int arr[], int n) {
    //Your code here
    map<int, int> m1;
    m1[0]=1;
    int x=0;
    for(int i=0; i<n; i++) {
        x += arr[i];
        m1[x]++;
        if(m1[x]==2) return true;
    }
    return false;
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

        cout<<subArrayExists(nums, n)<<"\n";
    }
}

/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(n)
*/
