/**
 * @file 04_remove_invalid_parentheses
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-15
 * @time 18:52
 * @link link
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
public:
    vector<pair<int, string>> ans;

    void solve(string &s, int i, string x, int opened, int closed) {
        if(i!=s.length()) {
            if(opened>=closed) {
                if(s[i]=='(') {
                    solve(s, i+1, x+s[i], opened+1, closed);
                    solve(s, i+1, x, opened, closed);
                } else if(s[i]==')') {
                    solve(s, i+1, x+s[i], opened, closed+1);
                    solve(s, i+1, x, opened, closed);
                } else {
                    solve(s, i+1, x+s[i], opened, closed);
                }
            }
        } else {
            if(opened==closed) ans.emplace_back(x.length(), x);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        solve(s, 0, "", 0, 0);
        sort(ans.rbegin(), ans.rend());
        set<string> ans2;
        for(auto i:ans) {
            if(ans[0].first==i.first) {
                ans2.insert(i.second);
            } else {
                break;
            }
        }
        vector<string> ans3;
        for(auto i:ans2) ans3.push_back(i);
        return ans3;
    }
};

signed main() {
    string str;
    cin >> str;
    Solution solution;
    vector<string> ans = solution.removeInvalidParentheses(str);
    for(auto i:ans) {
        cout << i << " ";
    }
    cout << endl;
}