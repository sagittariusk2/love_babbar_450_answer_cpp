/**
 * @file 08_divide
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-08
 * @time 14:19
 * @link https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x>> y;
        int t=y, ans=0;
        while(x>y)
            y <<= 1;
        while(y>=t) {
            ans <<= 1;
            if(x-y>=0) {
                ans+=1;
                x -= y;
            }
            else ans+=0;
            y >>= 1;
        }
        cout <<ans <<endl;
    }
}