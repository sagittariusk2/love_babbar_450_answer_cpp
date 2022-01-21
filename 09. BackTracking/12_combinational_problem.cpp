/**
 * @file 12_combinational_problem
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-18
 * @time 21:45
 * @link https://practice.geeksforgeeks.org/problems/combination-sum/0
 * @copyright Copyright (c) 2022
 */

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    void findNumbers(vector<vector<int>> &res, vector<int> &r, vector<int> &A, int sum, int i) {
        if(sum==0) {
            res.push_back(r);
            return;
        }
        while(i<A.size() and sum-A[i]>=0) {
            r.push_back(A[i]);
            findNumbers(res, r, A, sum-A[i], i);
            i++;
            r.pop_back();
        }
    }
  
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // sorting and removing the duplicates
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        int n = A.size();
        
        vector<vector<int>> res;
        vector<int> r;
        findNumbers(res, r, A, B, 0);
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends