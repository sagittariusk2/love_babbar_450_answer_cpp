/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1)
    Majority Element
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
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size) {
        int v1[1000001]={0};
        for(int i=0; i<size; i++) {
            v1[a[i]]++;
        }
        for(int i=0; i<=1000000; i++) {
            if(v1[i]>size/2) return i;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/