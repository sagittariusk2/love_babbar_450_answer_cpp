/**
 * @file 07_print_all_palindromic_partitions_of_a_string
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-20
 * @time 14:40
 * @link https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1/
 * @copyright Copyright (c) 2022
 */


using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    bool isPalindrom(string &x) {
        int n = x.length();
        for(int i=0; i<n/2; i++) {
            if(x[i]!=x[n-i-1]) return false;
        }
        return true;
    }

    vector<vector<string>> solve(string &s, int n, vector<vector<vector<string>>> &dp) {
        // cout << n << " ";
        if(!dp[n].empty()) return dp[n];
        vector<vector<string>> ans;
        if(n==0) {
            return dp[n] = ans;
        }
        int c = 1;
        for(int i=n-1; i>=0; i--) {
            string x = s.substr(i, c++);
            if(isPalindrom(x)) {
                vector<vector<string>> v1 = solve(s, n-c+1, dp);
                if(v1.empty()) {
                    ans.push_back({x});
                }
                for(auto j:v1) {
                    j.push_back(x);
                    ans.push_back(j);
                }
            }
        }
        // for(auto j:ans) {
        //     for(auto i:j) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return dp[n] = ans;
    }

    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<vector<string>>> dp(S.length()+1);
        vector<vector<string>> ans = solve(S, S.length(), dp);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends