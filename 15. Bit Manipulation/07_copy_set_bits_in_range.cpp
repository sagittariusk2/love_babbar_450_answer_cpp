/**
 * @file 07_copy_set_bits_in_range
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-08
 * @time 17:41
 * @link https://www.geeksforgeeks.org/copy-set-bits-in-a-range/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        for(int i=l; i<=r; i++) {
            int mask = 1 << (i-1);
            if(y & mask) {
                x |= mask;
            }
        }

        cout << x << endl;
    }
}