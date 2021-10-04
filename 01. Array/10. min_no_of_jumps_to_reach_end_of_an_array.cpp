/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0)
    Minimum no. of Jumps to reach end of an array
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

int minJumps(int arr[], int n) {
    // If the size of array is 1 then we are already at the end.
    if(n==1) return 0;

    // If first element is 0 then we cannot make a jump.
    if(arr[0]==0) return -1;

    // Ladder gives the maximum length of ladder we have at any particular index.
    // Stair gives the remaining steps left to cross current ladder.
    // Jump will give us the answer.
    int ladder=arr[0], stair=arr[0], jump=1;

    for(int i=1; i<n; i++) {
        if(i==n-1) return jump; // If we reached last index then return

        // Update ladder to the maximum possible length.
        ladder = max(ladder, i+arr[i]);

        // Use one stair to move forward.
        stair--;

        // If stairs are over i.e. We moved to the last of current ladder.
        if(stair==0) {
            //Jump to the next ladder.
            jump++;

            // Update current ladder to the best ladder that is available to us.
            stair = ladder-i;

            // If we have no ladder present at the moment, so return -1 as we can not move forward.
            if(stair<=0) return -1;
        }
    }
    return jump;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        cout<<minJumps(a, n);
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
