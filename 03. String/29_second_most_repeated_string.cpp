/*
    Question link :- (https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1)
    Question :- Second most repeated string in a sequence
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

string secFrequent (string arr[], int n) {
    map<string, int> mpp;
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }
    vector<pair<int, string>> v1;
    for(auto i:mpp) {
        v1.emplace_back(i.second, i.first);
    }
    sort(v1.rbegin(), v1.rend());
    string ans;
    for(int i=1; i<v1.size(); i++) {
        if(v1[i].first<v1[i-1].first) {
            ans=v1[i].second;
            break;
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string str[n];
        for(int i=0; i<n; i++)
            cin >> str[i];

        string ans = secFrequent(str, n);

        cout << ans <<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/