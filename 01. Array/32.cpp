/*
    Question link :- (https://practice.geeksforgeeks.org/problems/three-way-partitioning/1)
    Question :- Three way partitioning of an array around a given value
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

void threeWayPartition(vector<int>& array,int a, int b) {
    int n = array.size();
    int i=0, j=n-1;

    for(int k=0; k<n; k++) {
        if(array[k]>b) {
            swap(array[k], array[j--]);
            if(array[k]>b) k--;
        }
        if(k>=j) break;
    }

    for(int k=j; k>=0; k--) {
        if(array[k]<a) {
            swap(array[k], array[i++]);
            if(array[k]<a) k++;
        }
        if(k<=i) break;
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, a, b;
        cin>>n>>a>>b;

        vector<int> arr(n);

        for(int i=0; i<n; i++)
            cin>>arr[i];

        threeWayPartition(arr, a, b);

        for(int i=0; i<n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
