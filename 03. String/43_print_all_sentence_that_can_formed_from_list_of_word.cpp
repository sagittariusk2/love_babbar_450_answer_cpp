/*
    Question link :- (https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/)
    Question :- Recursively print all sentences that can be formed from list of word lists
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void make_sentence(int i, string s, vector<vector<string>> &input) {
    if(i==input.size()) {
        cout << s<< "\n";
    } else {
        int m=input[i].size();
        for(int k=0; k<m; k++) {
            make_sentence(i+1, s+' '+input[i][k], input);
        }
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<string>> input;
        for(int i=0; i<n; i++) {
            int m;
            cin>>m;
            vector<string> x;
            while(m--) {
                string s;
                cin >> s;
                x.push_back(s);
            }
            input.push_back(x);
        }
        make_sentence(0, "", input);

    }
}

/*
    Time Complexity :- O(pi(m[i])0<=i<n)
    Space Complexity :- O(pi(m[i])0<=i<n)
*/