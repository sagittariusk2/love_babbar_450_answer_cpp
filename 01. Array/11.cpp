/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int findDuplicate(vector<int>& nums) {
    int n=nums.size();
    for(auto i:nums) {
        // Check if the ith position is negative or not, if it is negative then return i
        if(nums[abs(i)]<0) return abs(i);

        // Make value at ith position negative
        nums[abs(i)]=0-nums[abs(i)];
    }
    return 1;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        cout<<findDuplicate(a);
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
