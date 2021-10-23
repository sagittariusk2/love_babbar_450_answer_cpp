/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1)
    Count triplets with sum smaller than X
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
	long long countTriplets(long long arr[], int n, long long sum) {
	    sort(arr, arr+n);
	    int ans=0;
	    for(int i=0; i<n; i++) {
	        int j=i+1, k=n-1;
	        while(j<k) {
	            if(arr[i]+arr[j]+arr[k]<sum) {
	                ans += (k-j);
	                j++;
	            } else {
	                k--;
	            }
	        }
	    }
	    return ans;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

/*
    Time Complexity :- O(n^2)
    Space Complexity :- O(1)
*/
