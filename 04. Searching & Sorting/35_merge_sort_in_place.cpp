/**
 * @file 35_merge_sort_in_place
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 01:47
 * @link https://www.geeksforgeeks.org/in-place-merge-sort/
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    //Function to merge the arrays.
    void merge(long long arr[], int s, int mid, int e) { 
        // code here
        int i=mid, j=mid+1;
        while(i>=0 and j<=e and arr[i]>arr[j]) {
            swap(arr[i--], arr[j++]);
        }
        sort(arr+s, arr+mid);
        sort(arr+mid+1, arr+e);
    }

    void mergeSort(long long arr[], int s, int e) {
        while(s<e) {
            int mid = (s+e)/2;
            mergeSort(arr, s, mid);
            mergeSort(arr, mid+1, e);
            merge(arr, s, mid, e);
        }
    }
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n;
	    cin >> n;
	    
	    long long arr1[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    Solution ob;
	    ob.mergeSort(arr1, 0, n-1); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends