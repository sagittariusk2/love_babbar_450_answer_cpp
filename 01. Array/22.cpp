/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#)
    Factorials of large numbers
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<int> factorial(int N){
    // code here
    if(N==0) {
        vector<int> ans(1, 1);
        return ans;
    }

    vector<int> ans = factorial(N-1);
    int n = ans.size();
    for(int i=0; i<n/2; i++) {
        swap(ans[i], ans[n-i-1]);
    }
    int carry=0;
    for(int i=0; i<n; i++) {
        int x = (ans[i]*N)+carry;
        carry = x/10;
        ans[i]=x%10;
    }
    while(carry!=0) {
        ans.push_back(carry%10);
        carry /= 10;
    }
    n = ans.size();
    for(int i=0; i<n/2; i++) {
        swap(ans[i], ans[n-i-1]);
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<int> ans = factorial(n);

        for(auto i:ans) {
            cout<<i;
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(n)
*/
