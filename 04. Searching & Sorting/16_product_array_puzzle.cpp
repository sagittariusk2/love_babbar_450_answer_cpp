/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1)
    Product array puzzle 
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
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<int> productExceptSelf(vector<int>& nums, int n) {
        if(n==1) {
            nums[0]=1;
            return nums;
        }
        vector<int> l(n), r(n);
        for(int i=0; i<n; i++) {
            if(i==0) l[i] = nums[0];
            else l[i] = l[i-1]*nums[i];
        }
        for(int i=n-1; i>=0; i--) {
            if(i==n-1) r[i] = nums[i];
            else r[i] = r[i+1]*nums[i];
        }
        for(int i=0; i<n; i++) {
            if(i==0) nums[i]=r[i+1];
            else if(i==n-1) nums[i]=l[i-1];
            else nums[i]=l[i-1]*r[i+1];
        }
        return nums;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
