/*
    Question link :- (https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/)
    Question :- Find Duplicate characters in a string
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<char> duplicate(string s) {
    map<char, int> mpp;
    for(auto i:s) {
        mpp[i]++;
    }
    vector<char> ans;
    for(auto i:mpp) {
        if(i.second>=2) ans.push_back(i.first);
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        vector<char> ans = duplicate(s);
        for(auto i:ans) cout<<i<<" ";
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
