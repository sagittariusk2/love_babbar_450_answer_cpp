/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/count-squares3649/1)
    Count Squares
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int countSquares(int N) {
    int x = sqrt(N);
    if(x*x==N) return x-1;
    else return x;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<countSquares(n)<<"\n";
    }
}

/*
    Time Complexity :- O(1)
    Space Complexity :- O(1)
*/
