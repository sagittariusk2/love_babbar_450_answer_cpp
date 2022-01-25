/**
 * @file 10_the_celebraty_problem
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 12:24
 * @link https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
 * @copyright Copyright (c) 2022
 */

//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        // code here
        for(int i=0; i<n; i++) {
            int x=0;
            for(int j=0; j<n; j++) {
                x += M[i][j];
            }
            if(x==0) {
                int y=0;
                for(int j=0; j<n; j++) {
                    if(i!=j) y += M[j][i];
                }
                if(y==n-1) return i;
            }
        }
        return -1;
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
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends