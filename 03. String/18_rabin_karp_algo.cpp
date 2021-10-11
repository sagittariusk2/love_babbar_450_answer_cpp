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

int hash_value(string s) {
    int val=0, n=s.size(), d=1;
    for(int i=n-1; i>=0; i--) {
        val = (val + (s[i]*d)%M)%M;
        d = (d*256)%M;
    }
    return val;
}

vector<int> rabin_karp(string str, string text) {
    int n=str.size(), m=text.size();

    vector<int> ans;

    int hash_val = hash_value(text);
    int x = hash_value(str.substr(0, m));
    int y = 1;
    for(int i=1; i<m; i++) {
        y = (y*256)%M;
    }

    if(x==hash_val) {
        int flag=0;
        for(int k=0, l=0; l<m; k++, l++) {
            if(text[l]!=str[k]) {
                flag=1;
                break;
            }
        }
        if(flag==0) ans.push_back(0);
    }

    for(int i=0, j=m; j<n; i++, j++) {
        x = ((x+M)-(str[i]*y)%M)%M;
        x = (x*256)%M;
        x = (x + str[j])%M;
        if(x==hash_val) {
            int flag=0;
            for(int k=i+1, l=0; l<m; k++, l++) {
                if(text[l]!=str[k]) {
                    flag=1;
                    break;
                }
            }
            if(flag==0) ans.push_back(i+1);
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str, text;
        cin>>str>>text;
        vector<int> ans = rabin_karp(str, text);
        for(auto i:ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/