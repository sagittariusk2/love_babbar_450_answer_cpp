/**
 * @file 08_subset_sum_problem
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-18
 * @time 18:26
 * @link https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
 * @copyright Copyright (c) 2022
 */


// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int equalPartition(int n, int arr[]) {
        int sum=0;
        for(int i=0; i<n; i++)
            sum += arr[i];
        if(sum%2==1) return 0;
        sum /= 2;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for(int i=0; i<n; i++) {
            for(int j=sum; j>=0; j--) {
                if(j-arr[i]>=0) dp[j] = max(dp[j], dp[j-arr[i]]);
            }
        }
        return dp[sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends