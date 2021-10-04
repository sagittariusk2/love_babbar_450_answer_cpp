/*
    Question link :- (https://leetcode.com/problems/median-of-two-sorted-arrays/)
    Question :- Median of Two Sorted Arrays
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

double median(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();

    if(n<m) {
        return median(nums2, nums1);
    } else {
        if(m==0) {
            if(n%2==0) return ((double)nums1[n/2-1]+(double)nums1[n/2])/2.0;
            else return (double)nums1[n/2];
        }
        int i=0, j=m, len=m+n;
        while(i<=j) {
            int mid = (i+j)/2;
            int y =((len+1)/2)-mid;

            int a1 = (y==0)?INT_MIN:nums1[y-1];
            int a2 = (y==n)?INT_MAX:nums1[y];
            int b1 = (mid==0)?INT_MIN:nums2[mid-1];
            int b2 = (mid==m)?INT_MAX:nums2[mid];

            if(a1<=b2 and a2>=b1) {
                if(len%2==1) return (double)max(a1, b1);
                else return ((double)max(a1, b1)+(double)min(a2, b2))/2.0;
            } else if(a2<b1) j = mid-1;
            else i = mid+1;
        }
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<int> nums1(n), nums2(m);
        for(int i=0; i<n; i++)
            cin>>nums1[i];
        
        for(int i=0; i<m; i++)
            cin>>nums2[i];

        cout<<median(nums1, nums2)<<"\n";
    }
}

/*
    Time Complexity :- O(min(logn, logm))
    Space Complexity :- O(1)
*/