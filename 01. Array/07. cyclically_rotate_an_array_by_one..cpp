/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0)
    Write a program to cyclically rotate an array by one.
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void rotate(int a[], int n) {
    int x=a[n-1];
    for(int i=n-1; i>=1; i--) {
        a[i]=a[i-1];
    }
    a[0]=x;
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

        rotate(nums, n);

        for(int i=0; i<n; i++) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
