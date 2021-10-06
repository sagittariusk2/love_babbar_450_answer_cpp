/*
    Question link :- (https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/)
    Question :- A Program to check if strings are rotations of each other or not
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
        while(j>0 && str[i]!=str[j]) {
            j = pi[j-1];
        }
        if(str[i]==str[j]) j++;
        pi[i] = j;
    }
    return pi;
}

bool checkRotation(string str1, string str2) {
    int n = str1.size();
    for(int i=0; i<n-1; i++)
        str2 += str2[i];
    
    //Get Pi function of the string.
    vector<int> pi = pi_function(str1+'#'+str2);

    for(auto i:pi) {
        if(i==n) return true;
    }
    return false;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str1, str2;
        cin >> str1 >> str2;
        cout << checkRotation(str1, str2) << "\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
