/*
    Question link :- (https://practice.geeksforgeeks.org/problems/next-permutation/0)
    Question :- Find next greater number with same set of digits. [Very Very IMP]
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<int> nextPermutation(int n, vector<int> &arr) {
    //Start pointer
    int i=n-2;
    while(i>=0 && arr[i]>arr[i+1]) {
        i--;
    }
    //End pointer
    int j=i+1;
    if(i!=-1) {
        while(j<n && arr[j]>arr[i]) {
            j++;
        }
        j--;
        swap(arr[i], arr[j]);
    }

    //sort remaining array
    sort(arr.begin()+i+1, arr.end());
    return arr;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }

        vector<int> ans = nextPermutation(n, arr);

        for(auto i:ans) cout<<i<<" ";
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/