/*
    Question link :- (https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#)
    Question :- Minimum Swaps for Bracket Balancing
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int minimumNumberOfSwaps(string s){
    int n=s.size(), x=0, ans=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='[') x++;
        else x--;
        if(x<0) {
            for(int j=i+1; j<n; j++) {
                if(s[j]=='[') {
                    swap(s[i], s[j]);
                    x+=2;
                    ans += (j-i);
                    break;
                }
            }
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin >> str ;
        cout << minimumNumberOfSwaps(str) << "\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/