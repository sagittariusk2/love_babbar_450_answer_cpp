/*
    Question link :- (https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0)
    Question :- Minimum swaps required bring elements less equal K together
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int minSwap(vector<int> arr, int n, int k) {
    // Complet the function
    int cnt=0;
    for(int i=0; i<n; i++) {
        if(arr[i]<=k) cnt++;
    }
    
    int temp_cnt=0;
    for(int i=0; i<cnt; i++) {
        if(arr[i]<=k) temp_cnt++;
    }
    
    int ans=cnt-temp_cnt;
    
    for(int i=0; i<n-cnt; i++) {
        if(arr[i]<=k) temp_cnt--;
        if(arr[i+cnt]<=k) temp_cnt++;
        ans = min(ans, cnt-temp_cnt);
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<int> arr(n);

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<minSwap(arr, n, k)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
