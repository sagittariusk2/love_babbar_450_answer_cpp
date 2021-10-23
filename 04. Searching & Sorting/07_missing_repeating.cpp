/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1)
    Find Missing And Repeating
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
    int *findTwoElement(int *arr, int n) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }
        
        int *ans;
        ans = (int*)malloc(sizeof(int)*2);
        
        for(int i=0; i<n; i++) {
            arr[i]--;
        }
        
        for(int i=0; i<n; i++) {
            int j=arr[i];
            while(j!=-1) {
                int x = arr[j];
                arr[j] = -1;
                j = x;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(arr[i]!=-1) {
                ans[1]=i+1;
                break;
            }
        }
        
        ans[0] = sum - (((long long)n*((long long)n+1))/2-(long long)ans[1]);
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/