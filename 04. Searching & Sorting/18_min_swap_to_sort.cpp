/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/minimum-swaps/1)
    Minimum Swaps to Sort
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
    
	int minSwaps(vector<int>&nums) {
	    int n = nums.size();
	    vector<pair<int, int>> v1;
	    for(int i=0; i<n; i++) {
	        v1.emplace_back(nums[i], i);
	    }
	    sort(v1.begin(), v1.end());
	    for(int i=0; i<n; i++) {
	        nums[i] = v1[i].second;
	    }
	    int ans=0;
	    for(int i=0; i<n; i++) {
	        int j = i;
	        if(j!=nums[j]) {
	            ans--;
	        }
	        while(j!=nums[j]) {
	            int x = nums[j];
	            nums[j] = j;
	            j = x;
	            ans++;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}

/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(n)
*/
