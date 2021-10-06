/*
    Question link :- (https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1)
    Question :- Trapping Rain Water
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int trap(vector<int>& height) {
    int n = height.size();

    vector<int> trap1(n, 0), trap2(n, 0);
    trap1[0]=height[0];

    for(int i=1; i<n; i++) {
        trap1[i]=max(trap1[i-1], height[i]);
    }

    trap2[n-1]=height[n-1];

    for(int i=n-2; i>=0; i--) {
        trap2[i]=max(trap2[i+1], height[i]);
    }

    int ans=0;

    for(int i=0; i<n; i++) {
        ans += (min(trap1[i], trap2[i])-height[i]);
    }

    return ans;
}


signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<trap(arr)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
