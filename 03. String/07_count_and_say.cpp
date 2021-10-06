/*
    Question link :- (https://leetcode.com/problems/count-and-say/)
    Question :- Count and Say
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

string countAndSay(int n) {
    string number="1";
    for(int i=2; i<=n; i++) {
        int count=1;
        char x=number[0];
        string ans;
        for(int j=1; j<number.length(); j++) {
            if(number[j]==number[j-1]) {
                count++;
            } else {
                ans += to_string(count)+x;
                count=1;
                x=number[j];
            }
        }
        ans += to_string(count)+x;
        number=ans;
    }
    return number;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<countAndSay(n)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
