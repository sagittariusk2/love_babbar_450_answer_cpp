/**
 * @file 31_roti_parata_spoj
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 01:03
 * @link https://www.spoj.com/problems/PRATA/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

bool canMake(vector<int>&v1, int n, int p, int mid) {
    int y=0, x[9];
    for(int i=1; i<=8; i++) {
        x[i] = (sqrt((i*i)+(8*mid*i))-i)/(2*i);
    }
    for(int i=0; i<n; i++) {
        y += x[v1[i]];
    }
    return (y>=p);
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int p, n;
        cin >> p >> n;
        vector<int> v1(n);
        for(int i=0; i<n; i++) {
            cin >> v1[i];
        }

        int s=0, e=1e8;
        while(s<e) {
            int mid = (s+e)/2;
            if(canMake(v1, n, p, mid)) {
                e = mid;
            } else {
                s = mid+1;
            }
        }
        cout << s << endl;
    }
}