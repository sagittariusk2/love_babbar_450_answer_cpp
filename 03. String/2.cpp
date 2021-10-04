/*
    Question link :- (https://practice.geeksforgeeks.org/problems/palindrome-string0817/1)
    Question :- Check whether a String is Palindrome or not
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int isPlaindrome(string S) {
	    int n = S.size();
	    int x = n/2;
	    for(int i=0; i<x; i++) {
	        if(S[i]!=S[n-i-1]) return 0;
	    }
	    return 1;
	}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<isPlaindrome(s)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
