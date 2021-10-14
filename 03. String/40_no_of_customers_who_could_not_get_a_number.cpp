/*
    Question link :- (https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/)
    Question :- Function to find Number of customers who could not get a computer
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int runCustomerSimulation(string str, int k) {
    vector<int> mp(26, 0), mp2(26, 0);
    int ans=0;
    for(auto i:str) {
        if(!mp[i-'A']) {
            mp[i-'A']++;
            if(k) {
                mp2[i-'A']=1;
                k--;
            } else ans++;
        } else {
            mp[i-'A']--;
            if(mp2[i-'A']) {
                mp2[i-'A']--;
                k++;
            }
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        int k;
        cin >> str >> k;
        cout<<runCustomerSimulation(str, k)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/