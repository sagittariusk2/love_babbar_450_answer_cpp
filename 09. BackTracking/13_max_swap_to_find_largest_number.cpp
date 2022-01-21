/**
 * @file 13_max_swap_to_find_largest_number
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-21
 * @time 01:08
 * @link https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps/0
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution {
public:
    //Function to find the largest number after k swaps.
    string ans;
    void solve(string &str, int k, int x) {
        if(k!=0) {
            int n = str.length();
            
            char mx = str[x];
            
            for(int j=x+1; j<n; j++) {
                mx = max(mx, str[j]);
            }
            if (mx != str[x])
                --k;
            // for(int i=0; i<n-1; i++) {
                for(int j=n-1; j>=x; j--) {
                    if(str[j]==mx) {
                        swap(str[j], str[x]);
                        ans = max(ans, str);
                        solve(str, k, x+1);
                        swap(str[x], str[j]);
                    }
                }
            // }
        }
    }
    
    string findMaximumNum(string str, int k) {
        ans = str;
        solve(str, k, 0);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends