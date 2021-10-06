/*
    Question link :- (https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/)
    Question :- Given an array of size n and a number k, fin all elements that appear more than " n/k " times.
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int countOccurence(vector<int> arr, int n, int k) {
    vector<int> v1(1000001, 0);
    for(int i=0; i<n; i++) {
        v1[arr[i]]++;
    }
    int x=n/k, ans=0;
    for(int i=0; i<=1000000; i++) {
        if(v1[i]>x) ans++;
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<int> arr(n);

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<countOccurence(arr, n, k)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
