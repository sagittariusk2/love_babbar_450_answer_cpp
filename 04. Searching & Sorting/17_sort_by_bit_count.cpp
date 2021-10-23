/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1)
    Sort by Set Bit Count
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

class Solution{
    public:
    void sortBySetBitCount(int arr[], int n) {
        vector<vector<int>> v1(21);
        for(int i=0; i<n; i++) {
            bitset<21> b1(arr[i]);
            v1[b1.count()].push_back(arr[i]);
        }
        int i=0;
        for(int j=20; j>=0; j--) {
            for(auto k:v1[j]) {
                arr[i++] = k;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(1)
*/
