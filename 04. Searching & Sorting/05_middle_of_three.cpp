/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/middle-of-three2926/1)
    Midle of three
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int middle(int A, int B, int C) {
    int a[3]={A, B, C};
    sort(a, a+3);
    return a[1];
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int a, b, c;
        cin>>a>>b>>c;
        cout<<middle(a, b, c)<<"\n";
    }
}

/*
    Time Complexity :- O(1)
    Space Complexity :- O(1)
*/
