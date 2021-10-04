/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0)
    Find the Union and Intersection of the two sorted arrays.
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<vector<int>> union_and_intersection(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> ans;
    vector<int> union_set, intersection;

    int i=0, j=0;

    while(i<n1 && j<n2) {
        if(nums1[i]<nums2[j]) {
            union_set.push_back(nums1[i++]);
        } else if(nums1[i]>nums2[j]) {
            union_set.push_back(nums2[j++]);
        } else {
            union_set.push_back(nums2[j++]);
            intersection.push_back(nums1[i++]);
        }
    }

    while(i<n1) {
        union_set.push_back(nums1[i++]);
    }

    while(j<n2) {
        union_set.push_back(nums2[j++]);
    }

    ans.push_back(union_set);
    ans.push_back(intersection);

    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n1, n2;
        cin>>n1>>n2;
        vector<int> nums1(n1), nums2(n2);
        for(int i=0; i<n1; i++) {
            cin>>nums1[i];
        }

        for(int i=0; i<n2; i++) {
            cin>>nums2[i];
        }

        vector<vector<int>> ans = union_and_intersection(nums1, nums2);

        for(auto i:ans) {
            for(auto j:i)
                cout<<j<<" ";
            cout<<"\n";
        }
    }
}

/*
    Time Complexity :- O(n1+n2)
    Space Complexity :- O(1)
*/
