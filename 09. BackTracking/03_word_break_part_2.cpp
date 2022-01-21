/**
 * @file 03_word_break_part_2
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-21
 * @time 00:59
 * @link https://practice.geeksforgeeks.org/problems/word-break-part-23249/1
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    vector<string> f_ans;
    void solve(vector<string>& dict, int i, string ans, string s1, string &s) {
        if(i<s.length()) {
            s1+=s[i];
            if(binary_search(dict.begin(), dict.end(), s1)) {
                string x;
                if(ans.empty()) x = ans + (s1);
                else x = ans + (' '+s1);
                solve(dict, i+1, x, "", s);
            }
            solve(dict, i+1, ans, s1, s);
        } else {
            if(s1=="") {
                f_ans.push_back(ans);
            }
        }
    }
    
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s) {
        sort(dict.begin(), dict.end());
        solve(dict, 0, "", "", s);
        return f_ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends