/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1)
    Zero Sum Subarrays
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    int findSubarray(vector<int> arr, int n ) {
        map<int, int> mp;
        mp[0]=1;
        int sum=0, ans=0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            ans += mp[sum];
            mp[sum]++;
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
        int n;
        cin>>n; //input size of array
       
        vector<int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
