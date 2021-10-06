/*
    Question link :- (https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1)
    Question :- Array Subset of another array
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

string isSubset(int a1[], int a2[], int n, int m) {
    vector<int> mp(100001, 0);
    
    for(int i=0; i<n; i++) {
        mp[a1[i]]++;
    }
    
    for(int i=0; i<m; i++) {
        mp[a2[i]]--;
        if(mp[a2[i]]<0) return "No";
    }
    return "Yes";
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n1, n2;
        cin>>n1>>n2;

        int a1[n1], a2[n2];

        for(int i=0; i<n1; i++)
            cin>>a1[i];

        for(int i=0; i<n2; i++)
            cin>>a2[i];

        cout<<isSubset(a1, a2, n1, n2)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
