/**
 * @file 28_arithmetic_number
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 01:42
 * @link https://practice.geeksforgeeks.org/problems/arithmetic-number/0
 * @copyright Copyright (c) 2022
 */

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        if(C==0) {
            if(A==B) return 1;
            return 0;
        }
        if((B-A<=0 and C<=0) or (B-A>=0 and C>=0))
        return ((B-A)%C==0);
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}  // } Driver Code Ends