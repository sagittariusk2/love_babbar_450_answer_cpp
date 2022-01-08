/**
 * @file 10_power_set
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-08
 * @time 13:44
 * @link https://practice.geeksforgeeks.org/problems/power-set4302/1
 * @copyright Copyright (c) 2022
 */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<string> AllPossibleStrings(string s) {
	    int n=s.length();
	    vector<string> v1;
	    for(int j=1; j<65536; j++) {
	        bitset<16> b1(j);
	        string ans;
	        for(int i=0; i<n; i++) {
	            if(b1[i]) {
	                ans += s[i];
	            }
	        }
	        v1.push_back(ans);
	        if(ans.length()==n) break;
	    }
	    sort(v1.begin(), v1.end());
	    return v1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends