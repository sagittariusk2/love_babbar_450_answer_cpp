/* 
    Question Link :- (https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/)
    Maximum and minimum of an array using minimum number of comparisons
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, ma, mi;
        cin>>n;
        vector<int> nums(n);

        for(int i=0; i<n; i++) {
            cin>>nums[i];
            if(i==0) {
                ma=nums[i];
                mi=nums[i];
            } else {
                ma = max(ma, nums[i]);
                mi = min(mi, nums[i]);
            }
        }

        cout<<ma<<" "<<mi<<"\n";

    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
