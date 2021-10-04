/*
    Question link :- (https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#)
    Question :- Kth smallest element
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int kthSmallest(int nums[], int start, int end, int k) {
    //Setting new randomisation
    srand(time(0));

    if(start<end) {
        
        //Swaping start index with the new random position
        swap(nums[start], nums[start + rand()%(end-start+1)]);
        int x = nums[start];
        int i=start+1, j=end;
        while(i<=j) {
            if(nums[i]<x) i++;
            else if(nums[j]>x) j--;
            else {
                swap(nums[i++], nums[j--]);
            }
        }
        swap(nums[start], nums[j]);
        if(j==k-1) return nums[j];
        else if(j>k-1) {
            return kthSmallest(nums, start, j-1, k);
        } else {
            return kthSmallest(nums, j+1, end, k);
        }
    }
    return nums[start];
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        cout<<kthSmallest(a, 0, n-1, k)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/