/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#)
    First and last occurrences of x
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<int> valueEqualToIndex(int arr[], int n) {
	vector<int> ans;
    for(int i=0; i<n; i++) {
	    if(arr[i]==i+1) ans.push_back(arr[i]);
	}
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int nums[n];
        for(int i=0; i<n; i++) {
            cin>>nums[i];
        }

        vector<int> ans = valueEqualToIndex(nums, n);

        for(auto i:ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(logn)
    Space Complexity :- O(1)
*/
