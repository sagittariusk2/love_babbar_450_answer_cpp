/*
    Question link :- (https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1#)
    Question :- Roman Number to Integer
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int romanToDecimal(string &str) {
    map<char, pair<int, int>> mpp;
    mpp['I']=make_pair(1, 0);
    mpp['V']=make_pair(5, 1);
    mpp['X']=make_pair(10, 2);
    mpp['L']=make_pair(50, 3);
    mpp['C']=make_pair(100, 4);
    mpp['D']=make_pair(500, 5);
    mpp['M']=make_pair(1000, 6);

    int n=str.size(), ans=0, max_i=0;
    for(int i=n-1; i>=0; i--) {
        if(mpp[str[i]].second>=max_i) {
            ans += mpp[str[i]].first;
        } else {
            ans -= mpp[str[i]].first;
        }
        max_i = max(max_i, mpp[str[i]].second);
    }

    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str1;
        cin >> str1;

        int ans = romanToDecimal(str1);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/