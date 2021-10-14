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

int ans1=INT_MAX;

void fun(vector<int> &a, int word, int line, int space_taken, int ans, int k) {
    if(space_taken<=k) {
        if(word==a.size()-1) {
            ans1 = min(ans1, ans);
        } else {
            fun(a, word+1, line, space_taken+1+a[word+1], ans, k);
            fun(a, word+1, line+1, a[word+1], ans+((k-space_taken)*(k-space_taken)), k);
        }
    }
}

int solveWordWrap(vector<int> arr, int k) {
    fun(arr, 0, 0, arr[0], 0, k);
    return ans1;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }

        int ans = solveWordWrap(arr, k);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(n^2)
*/