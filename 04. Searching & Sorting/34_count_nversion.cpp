/**
 * @file 34_count_nversion
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 01:46
 * @link https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    // long long merging(long long nums[], long long start, long long mid, long long end) {
    //     long long i=start, j=mid+1, ans=0;
    //     vector<long long> temp;
    //     while(i<=mid && j<=end) {
    //         if(nums[i]<=nums[j]) {
    //             temp.push_back(nums[i++]);
    //         } else {
    //             temp.push_back(nums[j++]);
    //             ans += (mid-i+1);
    //         }
    //     }
    //     while(i<=mid) {
    //         temp.push_back(nums[i++]);
    //     }
    //     while(j<=end) {
    //         temp.push_back(nums[j++]);
    //     }
    //     j=0;
    //     for(i=start; i<=end; i++) {
    //         nums[i]=temp[j++];
    //     }
    //     return ans;
    // }
    
    // long long solve(long long nums[], long long start, long long end) {
    //     if(start<end) {
    //         long long mid = (start+end)/2;
    //         long long x = solve(nums, start, mid);
    //         long long y = solve(nums, mid+1, end);
    //         long long z = merging(nums, start, mid, end);
    //         return x+y+z;
    //     }
    //     return 0;
    // }
    
    
    long long merge(long long a[], long long start, long long mid, long long end) {
        long long b[end-start+1];
        long long i=start, j=mid+1, ans=0, k=0;
        while(i<=mid and j<=end) {
            if(a[i]<=a[j]) {
                b[k++]=a[i++];
            } else {
                ans += (mid-i+1);
                b[k++]=a[j++];
            }
        }
        
        while(i<=mid) {
            b[k++]=a[i++];
        }
        while(j<=end) {
            b[k++]=a[j++];
        }
        
        k=0;
        for(int i=start; i<=end; i++) {
            a[i]=b[k++];
        }
        
        return ans;
    }
    
    long long solve(long long arr[], long long start, long long end) {
        if(start<end) {
            long long mid = (start+end)/2;
            
            long long x = solve(arr, start, mid);
            long long y = solve(arr, mid+1, end);
            long long z = merge(arr, start, mid, end);
            
            return x+y+z;
        }
        return 0;
    }
    
    long long int inversionCount(long long arr[], long long n) {
        // Your Code Here
        
        return solve(arr, 0, n-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends