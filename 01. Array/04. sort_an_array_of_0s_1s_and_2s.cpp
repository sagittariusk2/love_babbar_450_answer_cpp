/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1)
    Sort an array of 0s, 1s and 2s
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int z=0, o=0;
        for(int i=0; i<n; i++) {
            if(a[i]==0) z++;
            else if(a[i]==1) o++;
        }
        for(int i=0; i<n; i++) {
            if(z>0) {
                a[i]=0;
                z--;
            }
            else if(o>0) {
                a[i]=1;
                o--;
            }
            else a[i]=2;
        }
    }
    
};

// { Driver Code Starts.
signed main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
    }
    return 0;
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/
