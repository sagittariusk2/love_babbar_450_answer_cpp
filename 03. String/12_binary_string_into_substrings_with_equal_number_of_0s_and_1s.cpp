/*
    Question link :- (https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/)
    Question :- Split the binary string into substrings with equal number of 0s and 1s
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int equal0and1(string S) {
    int n=S.length(), count0=0, count1=0, count=0;
    for(int i=0; i<n; i++) {
        if(S[i]=='0') count0++;
        else count1++;
        if(count0==count1) count++;
    }
    if(count0!=count1 || count==0) return -1;
    return count;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<equal0and1(s)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/