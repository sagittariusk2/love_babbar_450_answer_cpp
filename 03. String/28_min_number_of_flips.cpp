/*
    Question link :- (https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1)
    Question :- Min number of flips
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int minFlips (string S) {
    int ans1=0, ans2=0, n=S.length();
    for(int i=0; i<n; i++) {
        if(i%2) {
            if(S[i]=='1') ans1++;
        } else {
            if(S[i]=='0') ans1++;
        }
    }
    
    for(int i=0; i<n; i++) {
        if(i%2) {
            if(S[i]=='0') ans2++;
        } else {
            if(S[i]=='1') ans2++;
        }
    }
    
    return min(ans1, ans2);
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str1;
        cin >> str1;

        int ans = minFlips(str1);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/