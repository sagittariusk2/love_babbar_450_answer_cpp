/**
 * @file 30_painters_partition_problem_11
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 01:44
 * @link https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
public:

    bool solve(int arr[], int n, int k, long long int mid) {
        long long int x=0,  y=1;
        for(int i=0; i<n; i++) {
            if(arr[i]+x<=mid) {
                x += arr[i];
            } else {
                x = arr[i];
                y++;
            }
        }
        return (y<=k);
    }

    long long minTime(int arr[], int n, int k) {
        long long int mx = 0;
        int mn = 0;
        for(int i=0; i<n; i++) {
            mx += arr[i];
            mn = max(mn, arr[i]);
        }
        long long int ans;
        while(mx>=mn) {
            int mid = (mx+mn)/2;
            if(solve(arr, n, k, mid)) {
                ans = mid;
                mx = mid-1;
            } else {
                mn = mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends