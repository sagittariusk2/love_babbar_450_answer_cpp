/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1)
    Find Pair Given Difference
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    int i=0, j=size-1;
    for(int i=0; i<size; i++) {
        if(binary_search(arr, arr+size, n+arr[i])) return true;
    }
    return false;
}

/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(1)
*/