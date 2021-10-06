/*
    Question link :- (https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings)
    Question :- Check if a string is a valid shuffle of two distinct strings
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool validSuffle(string str1, string str2, string str) {
    int map[26]={0};
    for(auto i:str1) {
        map[i-97]++;
    }
    for(auto i:str2) {
        map[i-97]++;
    }

    for(auto i:str) {
        map[i-97]--;
    }

    for(int i=0; i<26; i++) {
        if(map[i]!=0) return false;
    }

    return true;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str1, str2, str;
        cin>>str1>>str2>>str;
        cout<<validSuffle(str1, str2, str)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
