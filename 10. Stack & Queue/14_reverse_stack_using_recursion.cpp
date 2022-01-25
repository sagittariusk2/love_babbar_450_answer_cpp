/**
 * @file 14_reverse_stack_using_recursion
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 13:14
 * @link link
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

void insert_bottom(stack<int>&s, int temp) {
    if(s.empty()) {
        s.push(temp);
    } else {
        int x = s.top();
        s.pop();
        insert_bottom(s, temp);
        s.push(x);
    }
}

void reverse(stack<int> &s) {
    if(!s.empty()) {
        int temp = s.top();
        s.pop();
        reverse(s);
        insert_bottom(s, temp);
    }
}

signed main() {
    //code here
    int n;
    cin >> n;
    stack<int> s;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    reverse(s);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}