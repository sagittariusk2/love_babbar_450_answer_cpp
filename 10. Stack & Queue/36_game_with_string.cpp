/**
 * @file 36_game_with_string
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 11:49
 * @link https://practice.geeksforgeeks.org/problems/game-with-string4100/1
 * @copyright Copyright (c) 2022
 */

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int> v1(26, 0);
        for(auto i:s) {
            v1[i-'a']++;
        }
        
        priority_queue<pair<int, int>> qu;
        for(int i=0; i<26; i++) {
            qu.emplace(v1[i],i);
        }
        
        while(k--) {
            pair<int, int> x = qu.top();
            qu.pop();
            x.first--;
            qu.push(x);
        }
        int ans = 0;
        while(!qu.empty()) {
            ans += (qu.top().first*qu.top().first);
            qu.pop();
        }
        return ans;
        // sort(s.rbegin(), s.rend());
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends