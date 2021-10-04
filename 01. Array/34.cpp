/*
    Question link :- (https://practice.geeksforgeeks.org/problems/palindromic-array/0)
    Question :- Minimum no. of operations required to make an array palindrome
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int PalinArray(int a[], int n) {
    for(int i=0; i<n; i++) {
        string s=to_string(a[i]);
        int l=s.length();
        for(int k=0; k<l/2; k++) {
            if(s[k]!=s[l-k-1]) return 0;
        }
        
    }
    return 1;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        int arr[n];

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<PalinArray(arr, n)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/