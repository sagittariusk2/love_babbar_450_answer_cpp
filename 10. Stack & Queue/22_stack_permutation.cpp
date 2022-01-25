/**
 * @file 22_stack_permutation
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 23:31
 * @link https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

bool stackPermutation(queue<int> &q1, queue<int> &q2) {
    stack<int> st;

    while(!q1.empty()) {
        if(q2.front()!=q1.front()) {
            st.push(q1.front());
            q1.pop();
        } else {
            st.push(q1.front());
            q1.pop();
            while(!st.empty() and st.top()==q2.front()) {
                q2.pop();
                st.pop();
            }
        }
    }
    return q2.empty();
}

signed main() {
    int n;
    cin >> n;
    queue<int> q1, q2;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        q1.push(x);
    }
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        q2.push(x);
    }

    cout << stackPermutation(q1, q2) << endl;
}