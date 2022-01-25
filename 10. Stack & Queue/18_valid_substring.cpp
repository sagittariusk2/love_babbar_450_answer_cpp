/**
 * @file 18_valid_substring
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 16:50
 * @link https://practice.geeksforgeeks.org/problems/valid-substring0624/1
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
public:
    int findMaxLen(string s) {
        // code here
        stack<int> s1;
        s1.push(-1);
        int ans = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(') {
                s1.push(i);
            } else {
                s1.pop();
                if(!s1.empty()) {
                    ans = max(ans, i-s1.top());
                } else {
                    s1.push(i);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends