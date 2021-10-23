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

// Brute Force :- Time complexity :- O(n^2), Space Complexity :- O(1)

// Binary Search approach

int solve_for_lower(int a[], int s, int e, int k) {
	if(s!=e) { // Enter the block if more partition could be done.
		// get the middle element
		int mid = (s+e)/2;
		
		// if `k` is smaller than or equal to middle element
		if(a[mid]>=k) {
			// decrease `e` to mid for search in left half.
			e = mid;
		}
		// if `k` is greater than middle element
		else {
			// increase `s` to mid+1 for search in right half.
			s = mid+1;
		}
		
		//call recurssive function in required half.
		return solve_for_lower(a, s, e, k);
	}
	
	// if `a[s]` matches with `k`, then number found with lowest possible index.
	if(a[s]==k) return s;
	
	// if `a[s]` does not match with `k` with, then number is not found in the array.
	return -1;
}

int solve_for_upper(int a[], int s, int e, int k) {
	if(s!=e) { // Enter the block if more partition could be done.
	
		// get the middle element
		int mid = (s+e)/2+((s+e)%2);
		
		// if `k` is greater than or equal to middle element
		if(a[mid]<=k) {
			// increase `s` to mid for search in right half.
			s = mid;
		}
		// if `k` is smaller than middle element
		else {
			// decrease `e` to mid-1 for search in left half.
			e = mid-1;
		}
		
		//call recurssive function in required half.
		return solve_for_upper(a, s, e, k);
	}
	
	// if `a[s]` matches with `k`, then number found with largest possible index.
	if(a[s]==k) return s;
	
	// if `a[s]` does not match with `k` with, then number is not found in the array.
	return -1;
}

vector<int> find(int arr[], int n , int x ) {
    vector<int> ans(2);
    ans[0] = solve_for_lower(arr, 0, n-1, x);
    ans[1] = solve_for_upper(arr, 0, n-1, x);
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;
        int nums[n];
        for(int i=0; i<n; i++) {
            cin>>nums[i];
        }

        vector<int> ans = find(nums, n, x);

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
