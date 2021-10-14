/*
    Question link :- (https://practice.geeksforgeeks.org/problems/print-anagrams-together/1)
    Question :- Print Anagrams Together
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<vector<string> > Anagrams(vector<string>& string_list) {
    vector<vector<string>> ans;
    map<string, int> mp;
    int k=0;
    for(auto i:string_list) {
        string s=i;
        sort(s.begin(), s.end());
        if(mp.find(s)==mp.end()) {
            mp[s]=(k++);
            vector<string> x;
            x.push_back(i);
            ans.push_back(x);
        } else{
            ans[mp[s]].push_back(i);
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for(int i=0; i<n; i++) {
            cin>>string_list[i];
        }
        vector<vector<string>> ans = Anagrams(string_list);
        for(auto i:ans) {
            for(auto j:i) {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
}

/*
    Time Complexity :- O(n*|s|)
    Space Complexity :- O(n*|s|)
*/