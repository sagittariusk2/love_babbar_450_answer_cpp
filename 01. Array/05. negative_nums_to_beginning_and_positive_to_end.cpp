/* 
    Question Link :- (https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/)
    Move all negative numbers to beginning and positive to end
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void move_negative(vector<int> &nums) {
    int n = nums.size();
    int i=0, j=n-1;
    while(i<j) {
        if(nums[i]<0) i++;
        else if(nums[j]>=0) j--;
        else {
            swap(nums[i++], nums[j--]);
        }
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) {
            cin>>nums[i];
        }

        move_negative(nums);

        for(auto i:nums) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
