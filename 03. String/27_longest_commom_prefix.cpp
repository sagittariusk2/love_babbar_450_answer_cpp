/*
    Question link :- (https://leetcode.com/problems/longest-common-prefix/)
    Question :- Longest Common Prefix
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

string longestCommonPrefix(vector<string>& strs) {
    string ans=strs[0];
    for(auto i:strs) {
        int k=-1, g=0;
        for(auto j:i) {
            k++;
            if(j!=ans[k]) {
                g++;
                break;
            }
        }
        if(g==0) k++;
        ans = ans.substr(0, k);
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> str1(n);
        for(int i=0; i<n; i++) {
            cin >> str1[i];
        }

        string ans = longestCommonPrefix(str1);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/