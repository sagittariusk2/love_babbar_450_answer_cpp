/*
    Question link :- (https://www.geeksforgeeks.org/rearrange-array-in-alternating-positive-negative-items-with-o1-extra-space-set-2/)
    Question :- Rearrange array in alternating positive & negative items with O(1) extra space
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void rearrange(vector<int> &nums) {
    int n = nums.size();
    int i=0, j=n-1;
    while(i<j) {
        if(nums[i]<0) i++;
        else if(nums[j]>=0) j--;
        else swap(nums[i++], nums[j--]);
    }

    j=0;
    while(j<n and nums[j]<0) {
        j+=2;
    }
    i=1;
    while(i<n && j<n) {
        swap(nums[i], nums[j]);
        i+=2;
        j+=2;
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);

        for(int i=0; i<n; i++)
            cin>>a[i];

        rearrange(a);

        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";

    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
