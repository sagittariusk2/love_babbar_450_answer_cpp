/* 
    Question Link :- (https://leetcode.com/problems/merge-intervals/)
    Merge intervals
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

// Brute Force :- Time complexity :- O(n^2), Space Complexity :- O(1)

// Sorting approach

bool comp(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    //Sorting according to the first element
    sort(intervals.begin(), intervals.end(), comp);

    vector<vector<int>> ans;
    vector<int> x(2, 0);
    int next=1, s=0;
    for(auto i:intervals) {
        // For the first time
        if(next==1) {
            x[0]=i[0];
            next=0;
        } else if(s<i[0]) {
            x[1]=s;
            ans.push_back(x);
            x[0]=i[0];
        }
        s=max(s, i[1]);
    }
    x[1]=s;
    ans.push_back(x);

    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> intervals;
        vector<int> temp(2);
        for(int i=0; i<n; i++) {
            cin>>temp[0]>>temp[1];
            intervals.push_back(temp);
        }

        vector<vector<int>> ans = merge(intervals);

        for(auto i:ans) {
            cout<<i[0]<<" "<<i[1]<<"\n";
        }
    }
}

/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(1)
*/
