/*
    Question link :- (https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1)
    Question :- Smallest distinct window
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool equal(vector<int> &mpp, vector<int> &curr_mpp) {
    for(int i=0; i<52; i++) {
        if(curr_mpp[i]>0 xor mpp[i]>0) return false;
    }
    return true;
}

string findSubString(string str) {
    vector<int> mpp(52, 0), curr_mpp(52, 0);
    for(auto i:str) {
        if(i>='a' and i<='z') mpp[i-97]++;
        else mpp[i-39]++;
    }

    int n=str.size();
    int i=0, j=0, ii=0, jj=0, ans=n;
    while(i<n and j<n) {
        if(str[j]>='a' and str[j]<='z') curr_mpp[str[j++]-97]++;
        else curr_mpp[str[j++]-39]++;
        while(equal(mpp, curr_mpp)) {
            if(ans>=j-i) {
                ii=i, jj=j;
                ans=j-i;
            }
            if(str[i]>='a' and str[i]<='z') curr_mpp[str[i++]-97]--;
            else curr_mpp[str[i++]-39]--;
        }
    }
    return str.substr(ii, jj-ii);
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin >> str;
        cout<<findSubString(str)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/