/*
    Question link :- (https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#)
    Question :- Count the Reversals
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int countRev (string s) {
    int n = s.length();
    if(n%2==1) return -1;
    int ans=0, ans2=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='{') ans++;
        else ans--;
        if(i+ans>=n or ans<0) {
            if(s[i]=='{') ans-=2;
            else ans+=2;
            ans2++;
        }
    }
    return ans2;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin >> str;

        int ans = countRev(str);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(min(m, n))
*/