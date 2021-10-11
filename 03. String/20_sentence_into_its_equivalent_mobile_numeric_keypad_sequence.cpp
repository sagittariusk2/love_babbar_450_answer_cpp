/*
    Question link :- (https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/)
    Question :- Convert a sentence into its equivalent mobile numeric keypad sequence
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

string printSequence(string str) {
    string ans;

    string mp[]={"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    for(auto i:str) {
        if(i==' ') ans += '0';
        else ans += mp[i-65];
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        cout<<printSequence(str)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/