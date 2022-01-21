/**
 * @file 32_doubleHelix
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-13
 * @time 12:25
 * @link https://www.spoj.com/problems/ANARC05B/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    while(1) {
        int n1;
        cin >> n1;
        if(n1==0) break;
        vector<int> nums1(n1), sum1(n1);
        for(int i=0; i<n1; i++) {
            cin >> nums1[i];
            sum1[i] = nums1[i];
            if(i!=0) sum1[i] += sum1[i-1];
        }
        int n2;
        cin >> n2;
        vector<int> nums2(n2), sum2(n2);
        for(int i=0; i<n2; i++) {
            cin >> nums2[i];
            sum2[i] = nums2[i];
            if(i!=0) sum2[i] += sum2[i-1];
        }
        int meetI=-1, meetJ=-1, ans=0;
        for(int i=0; i<n1; i++) {
            if(binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                int j = lower_bound(nums2.begin(), nums2.end(), nums1[i])-nums2.begin();
                int x, y;
                if(meetI==-1) {
                    x = sum1[i];
                    y = sum2[j];
                } else {
                    x = sum1[i]-sum1[meetI];
                    y = sum2[j]-sum2[meetJ];
                }
                meetI = i;
                meetJ = j;
                ans += max(x, y);
            }
        }
        int x, y;
        if(meetI==-1) {
            x = sum1[n1-1];
            y = sum2[n2-1];
        } else {
            x = sum1[n1-1]-sum1[meetI];
            y = sum2[n2-1]-sum2[meetJ];
        }
        ans += max(x, y);
        cout << ans << endl;
    }
}