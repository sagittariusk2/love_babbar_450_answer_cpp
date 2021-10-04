/*
    Question link :- (https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/)
    Question :- Reverse the array
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void reverseArray(int nums[], int n){
    for(int i=0; i<n/2; i++) {
        swap(nums[i], nums[n-i-1]);
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        reverseArray(a, n);

        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
