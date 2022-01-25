/**
 * @file 17_largest_rectangular_area_in_histogram
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 15:29
 * @link https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n) {
        // Your code here
        vector<long long> l(n), r(n);
        stack<long long> sl, sr;
        for(int i=0; i<n; i++) {
            while(!sl.empty() and arr[sl.top()]>=arr[i]) {
                sl.pop();
            }
            if(sl.empty()) l[i] = 0;
            else l[i] = sl.top()+1;
            sl.push(i);
        }
        for(int i=n-1; i>=0; i--) {
            while(!sr.empty() and arr[sr.top()]>=arr[i]) {
                sr.pop();
            }
            if(sr.empty()) r[i] = n-1;
            else r[i] = sr.top()-1;
            sr.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, arr[i]*(r[i]-l[i]+1));
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends