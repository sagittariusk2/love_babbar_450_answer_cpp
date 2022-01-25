/**
 * @file 37_first_non_repeating_charcter_in_a_stream
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 10:28
 * @link https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
 * @copyright Copyright (c) 2022
 */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    string FirstNonRepeating(string A) {
        queue<char> q1;
        string ans;
        ans += A[0];
        q1.push(A[0]);
        vector<int> v1(26, 0);
        v1[A[0]-97]++;
        for(int i=1; i<A.size(); i++) {
            v1[A[i]-97]++;
            q1.push(A[i]);
            while(!q1.empty() and v1[q1.front()-97]>=2) {
                q1.pop();
            }
            if(q1.empty()) ans += '#';
            else ans += q1.front();
        }
        return ans;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends