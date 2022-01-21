/**
 * @file 19_find_the_kth_permutation_sequence_of_first_n_natural_numbers
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-21
 * @time 01:13
 * @link https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-n-natural-numbers/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

int fact(int n, vector<int> &factorial) {
    if(n==0) return factorial[n] = 1;
    return factorial[n] = fact(n-1, factorial)*n;
}

void solve(vector<int> &ans, vector<int> &v1, int k, vector<int> &factorial) {
    if(!v1.empty()) {
        int n = v1.size();
        int na = factorial[n-1];
        int i = k/na;
        ans.push_back(v1[i]);
        for(int j=i+1; j<n; j++) {
            swap(v1[j], v1[j-1]);
        }
        v1.pop_back();
        solve(ans, v1, k%na, factorial);
    }
}

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> v1;
    for(int i=1; i<=n; i++) {
        v1.push_back(i);
    }
    vector<int> factorial(n+1);
    fact(n, factorial);
    vector<int> ans;
    solve(ans, v1, k, factorial);

    for(auto i:ans) {
        cout << i << " ";
    }
    cout << endl;
}