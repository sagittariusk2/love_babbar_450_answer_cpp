/**
 * @file 26_eko_spoj
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-22
 * @time 16:36
 * @link https://www.spoj.com/problems/EKO/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    for(int i=0; i<n; i++) {
        cin >> v1[i];
    }

    int i=0, j=2000000000;
    while (i<j) {
        int mid = (i+j)/2;
        int x = 0;
        for(int k=0; k<n; k++) {
            if(v1[k]>mid) {
                x += (v1[k]-mid);
            }
        }
        if(x<m) {
            j=mid;
        } else {
            i=mid+1;
        }
    }
    cout << i-1 << endl;
}