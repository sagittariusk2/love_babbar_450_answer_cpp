/**
 * @file 09_power_without_using_operator
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-08
 * @time 13:58
 * @link https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    bitset<16> b(n);
    int temp=n, ans=0;
    for(int i=0; i<16; i++) {
        if(b[i]) {
            ans += temp;
        }
        temp <<= 1;
    }

    cout << ans << "\n";
}