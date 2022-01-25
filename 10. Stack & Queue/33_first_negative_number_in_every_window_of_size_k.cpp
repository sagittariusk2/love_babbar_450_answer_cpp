/**
 * @file 33_first_negative_number_in_every_window_of_size_k
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 12:14
 * @link https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K){
    queue<long long> q1;
    vector<long long> ans;
    for(long long i=0; i<K; i++) {
        if(A[i]<0) q1.push(i);
    }
    if(q1.empty()) ans.push_back(0);
    else ans.push_back(A[q1.front()]);
    for(long long i=K; i<N; i++) {
        if(!q1.empty() and i-K==q1.front()) q1.pop();
        if(A[i]<0) q1.push(i);
        if(q1.empty()) ans.push_back(0);
        else ans.push_back(A[q1.front()]);
    }
    return ans;
}