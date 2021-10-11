/*
    Question link :- (https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)
    Question :- Rabin-Karp Algorithm for Pattern Searching
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<int> pi_function(string str) {
    int n = str.size();
    vector<int> pi(n, 0);
    for(int i=1; i<n; i++) {
        int j = pi[i-1];
        while(j>0 and str[i]!=str[j]) {
            j = pi[j-1];
        }
        if(str[i]==str[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int lps(string s) {
	vector<int> pi = pi_function(s);
    return *pi.rbegin();
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        cout<<lps(str)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/