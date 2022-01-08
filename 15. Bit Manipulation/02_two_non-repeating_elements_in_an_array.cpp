/**
 * @file 02_two_non-repeating_elements_in_an_array
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-08
 * @time 18:36
 * @link https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
 * @copyright Copyright (c) 2022
 */


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) {
        int a=0;
        for(auto i:nums) {
            a ^= i;
        }
        int b = a & (~(a-1));
        a = a^b;
        int a1=0, b1=0;
        for(auto i:nums) {
            if((int)(b & i) == b) {
                a1 ^= i;
            } else {
                b1 ^= i;
            }
        }
        vector<int> ans;
        ans.push_back(a1);
        ans.push_back(b1);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends