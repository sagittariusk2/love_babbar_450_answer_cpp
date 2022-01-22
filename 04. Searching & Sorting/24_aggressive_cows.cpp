/**
 * @file 24_aggressive_cows
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-22
 * @time 18:12
 * @link link
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

bool feasible(int mid, vector<int>&v1, int c) {
    int y=1, x=v1[0];
    for(auto i:v1) {
        if((i-x)>=mid) {
            y++;
            x = i;
        }
    }
    return (y>=c);
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<int> v1(n);
        for(int i=0; i<n; i++) {
            cin >> v1[i];
        }
        
        sort(v1.begin(), v1.end());
        int mn=INT_MAX, mx = v1[0];
        for(int i=1; i<n; i++) {
            mn = min(mn, v1[i]-v1[i-1]);
            mx = max(mx, v1[i]);
        }

        int s = mn, e = mx, ans=mn;
        while(s<e) {
            int mid = (s+e)/2;
            if(feasible(mid, v1, c)) {
                ans = mid;
                s=mid+1;
            } else {
                e=mid;
            }
        }
        cout << ans << endl;
    }
}