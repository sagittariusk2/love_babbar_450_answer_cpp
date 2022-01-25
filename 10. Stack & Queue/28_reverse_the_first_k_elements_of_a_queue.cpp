/**
 * @file 28_reverse_the_first_k_elements_of_a_queue
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 15:12
 * @link https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
 * @copyright Copyright (c) 2022
 */

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    vector<int> v1, v2;
    while(k--) {
        v1.push_back(q.front());
        q.pop();
    }
    while(!q.empty()) {
        v2.push_back(q.front());
        q.pop();
    }
    for(int i=v1.size()-1; i>=0; i--) {
        q.push(v1[i]);
    }
    for(auto i:v2) {
        q.push(i);
    }
    return q;
}