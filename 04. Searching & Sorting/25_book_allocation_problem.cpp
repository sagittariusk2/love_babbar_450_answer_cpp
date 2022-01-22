/**
 * @file 25_book_allocation_problem
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 01:41
 * @link https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
 * @copyright Copyright (c) 2022
 */

// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution {
    
    bool solve(int A[], int n, int m, int mid) {
        int x=0, y=1;
        for(int i=0; i<n; i++) {
            if(x+A[i]<=mid) {
                x += A[i];
            } else {
                x = A[i];
                y++;
            }
        }
        return (y<=m);
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) {
        int mn=0, mx=0;
        for(int i=0; i<N; i++) {
            mx += A[i];
            mn = max(mn, A[i]);
        }
        
        int ans=-1;
        while(mn<=mx) {
            int mid = (mn+mx)/2;
            if(solve(A, N, M, mid)) {
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

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends