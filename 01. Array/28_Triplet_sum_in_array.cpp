/*
    Question link :- (https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1)
    Question :- Triplet Sum in Array
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool find3Numbers(int A[], int n, int X) {
    sort(A, A+n);

    for(int i=0; i<n-2; i++) {
        int j=i+1, k=n-1, x=X-A[i];
        while(j<k) {
            if(A[j]+A[k]>x) {
                k--;
            } else if(A[j]+A[k]<x) {
                j++;
            } else {
                return true;
            }
        }
    }

    return false;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;

        int arr[n];

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<find3Numbers(arr, n, k)<<"\n";
    }
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(1)
*/
