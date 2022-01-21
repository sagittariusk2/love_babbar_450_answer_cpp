/**
 * @file 18_partition_of_set_into_k_equal_subset_with_equal_sum
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-19
 * @time 14:29
 * @link https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
public:

    bool solve(vector<int> &v2, int i, int x, int k, int sum) {
        // cout << k << " " << sum << " ";
        if(sum==0 and x==k) return true;
        if(i<v2.size()) {
            // cout << " " << v2[i] << endl;
            bitset<10> b1(sum), b2(v2[i]);
            int y=0;
            for(int i=0; i<10; i++) {
                if(b1[i]==0 and b2[i]==1) {
                    y++;
                    break;
                }
            }
            if(y==0 and sum-v2[i]>=0) return (solve(v2, i+1, x, k, sum) or solve(v2, i+1, x+1, k, sum-v2[i]));
            else return solve(v2, i+1, x, k, sum);
        }
        return false;
    }

    bool isKPartitionPossible(int a[], int n, int k) {
        int sum=0;
        for(int i=0; i<n; i++) sum += a[i];
        if(sum%k!=0) return false;
        sum /= k;
        int na = 1<<n;
        vector<int> v1(na, 0);
        for(int i=1; i<na; i++) {
            int x = log2(i);
            v1[i] = a[x] + v1[i-(1<<x)];
        }
        vector<int> v2;
        for(int i=0; i<na; i++) {
            if(v1[i]==sum) v2.push_back(i);
        }
        return solve(v2, 0, 0, k, (1<<n)-1);
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends