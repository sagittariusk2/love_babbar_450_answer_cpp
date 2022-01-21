/**
 * @file 10_tug_of_war
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-20
 * @time 00:37
 * @link https://www.geeksforgeeks.org/tug-of-war/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<vector<int>, vector<int>> tugOfWar(vector<int> &v1) {
    int n = v1.size();
    int na = 1<<n;
    vector<int> v2(na, 0);
    for(int i=1; i<na; i++) {
        int x = log2(i);
        v2[i] = v1[x] + v2[i-(1<<x)];
    }
    int x = (1<<n)-1;
    n = n/2;
    int mn = INT_MAX, ans = -1;
    for(int i=0; i<na; i++) {
        bitset<32> b1(i);
        if(b1.count()==n) {
            int diff = abs(v2[i]-v2[x-i]);
            if(mn>diff) {
                mn = diff;
                ans = i;
            }
        }
    }

    vector<int> ans1, ans2;
    ans = max(ans, x-ans);
    string y="";
    while(ans) {
        if(ans%2) y+='1';
        else y+='0';
        ans/=2;
    }

    for(int i=0; i<y.length(); i++) {
        if(y[i]=='1') ans1.push_back(v1[i]);
        else ans2.push_back(v1[i]);
    }
    return make_pair(ans1, ans2);
}

signed main() {
    int n;
    cin >> n;
    vector<int> v1(n);
    for(int i=0; i<n; i++) {
        cin >> v1[i];
    }

    pair<vector<int>, vector<int>> ans = tugOfWar(v1);

    for(auto i:ans.first) {
        cout << i << " ";
    }
    cout << endl;
    for(auto i:ans.second) {
        cout << i << " ";
    }
    cout << endl;
}