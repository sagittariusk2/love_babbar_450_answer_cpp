/*
    Question link :- (https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1)
    Question :- Longest Palindromic Substring
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void solve(string s, set<int> direction, string temp, vector<string> &ans, int n) {
	if(direction.size()==n) {
        ans.push_back(temp);
	} else {
        for(int i=0; i<n; i++) {
	        if(direction.find(i)==direction.end()) {
	            direction.insert(i);
	            solve(s, direction, temp+s[i], ans, n);
                direction.erase(i);
	        }
	    }
	}
}
	
void solve2(string s, int l, int r, vector<string> &ans) {
	if(l==r) ans.push_back(s);
    else {
	    for(int i=l; i<=r; i++) {
	        swap(s[i], s[l]);
            solve2(s, l+1, r, ans);
	        swap(s[i], s[l]);
	    }
	}
}
	
vector<string> find_permutation(string S) {
	vector<string> ans;
    int n = S.length();
	set<int> direction;

	// solve(S, direction, "", ans, n);
    solve2(S, 0, n-1, ans);
	sort(ans.begin(), ans.end());
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        vector<string> ans = find_permutation(s);

        for(auto i:ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n*n!)
    Space Complexity :- O(1)
*/
