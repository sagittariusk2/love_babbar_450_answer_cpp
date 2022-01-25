/**
 * @file 29_interleave_the_first_half_and second_half_of_queue
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-25
 * @time 14:25
 * @link https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=1
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

void reverse(queue<int>&q) {
    if(!q.empty()) {
        int x = q.front();
        q.pop();
        reverse(q);
        q.push(x);
    }
}

void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    int n=q.size();
    stack<int> st;
    for(int i=0; i<n/2; i++) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    for(int i=0; i<n/2; i++) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        q.push(q.front());
        st.pop();
        q.pop();
    }
    reverse(q);
}

signed main() {
    //code here
}