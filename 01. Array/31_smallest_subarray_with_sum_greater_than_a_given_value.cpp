/*
    Question link :- (https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0)
    Question :- Smallest Subarray with sum greater than a given value
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int smallestSubWithSum(int arr[], int n, int x) {
    for(int i=1; i<n; i++) {
        arr[i] += arr[i-1];
    }

    int i=-1, j=0, ans=n;
    while(i<n && j<n) {
        if(i==-1) {
            if(arr[j]<=x) j++;
            else {
                ans = min(ans, j-i);
                i++;
            }
        } else {
            if(arr[j]-arr[i]>x) {
                ans = min(ans, j-i);
                i++;
            } else {
                j++;
            }
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;

        int arr[n];

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<smallestSubWithSum(arr, n, x)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
