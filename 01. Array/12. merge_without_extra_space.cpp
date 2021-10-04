/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1)
    Merge Without Extra Space
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

// Optimized Approach (2 pointer) This is 100% faster in C++
void merge(int arr1[], int arr2[], int n, int m) {
    // Initialize two pointer, one at the end of first array and second at the start of 2nd array
    int i=n-1, j=0;
	while(i>=0 && j<m) {
        // Swap the elements if arr1 has larger number then 2nd arr2.
        // Else break it.
	    if(arr1[i]>arr2[j]) {
            swap(arr1[i], arr2[j]);
            i--, j++;
	    } else {
	        break;
        }
	}

    //Now sort both array to get the answer.
    sort(arr1, arr1+n);
	sort(arr2, arr2+m);
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        int arr1[n], arr2[m];
        for(int i=0; i<n; i++) {
            cin>>arr1[i];
        }
        for(int i=0; i<m; i++) {
            cin>>arr2[i];
        }

        merge(arr1, arr2, n, m);

        for(int i=0; i<n; i++) {
            cout<<arr1[i]<<" ";
        }
        cout<<"\n";
        for(int i=0; i<m; i++) {
            cout<<arr2[i]<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(nlogn)
    Space Complexity :- O(1)
*/
