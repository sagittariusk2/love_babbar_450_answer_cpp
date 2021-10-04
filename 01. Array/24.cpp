/*
    Question link :- (https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0)
    Question :- Find longest coinsecutive subsequence
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int findLongestConseqSubseq(int arr[], int N) {
    vector<int> sequence(100001, 0);
    for(int i=0; i<N; i++) {
        sequence[arr[i]]=1;
    }
    int ans=0, count=0;
    for(int i=0; i<=100000; i++) {
        if(sequence[i]==0) {
            count=0;
        } else {
            count++;
        }
        ans=max(ans, count);
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        int arr[n];

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<findLongestConseqSubseq(arr, n)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
