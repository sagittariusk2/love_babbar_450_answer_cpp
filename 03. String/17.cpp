/*
    Question link :- (https://practice.geeksforgeeks.org/problems/word-break/0)
    Question :- Word break Problem[ Very Imp]
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

//TRIE solution
bool solve(int i, string A, set<string> &setB) {
    int n = A.size();
    if(i<n) {
        string x="";
        bool ans=false;
        for(int j=i; j<n; j++) {
            x += A[j];
            if(setB.find(x)!=setB.end()) {
                if(j==n-1) return true;
                else ans = ans or solve(j+1, A, setB);
            }
        }
        return ans;
    }
    return false;
}

int wordBreak(string A, vector<string> &B) {
    //code here
    set<string> setB;
    for(auto i:B) {
        setB.insert(i);
    }
    return solve(0, A, setB);
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> dict(n);
        for(int i=0; i<n; i++)
            cin>>dict[i];
        string s;
        cin>>s;
        cout<<wordBreak(s, dict)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/