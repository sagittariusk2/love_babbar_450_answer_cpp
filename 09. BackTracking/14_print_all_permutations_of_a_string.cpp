/**
 * @file 14_print_all_permutations_of_a_string
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-20
 * @time 00:21
 * @link https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
 * @copyright Copyright (c) 2022
 */


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<string> ans;
    void solve(int n, string &s) {
        if(n==s.length()) {
            ans.push_back(s);
            return;
        }
        for(int i=n; i<s.length(); i++) {
            swap(s[i], s[n]);
            solve(n+1, s);
            swap(s[i], s[n]);
        }
    }

	vector<string>find_permutation(string S) {
	    solve(0, S);
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends