/**
 * @file _next_smaller_element
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-25
 * @time 10:54
 * @link https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=1
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() and arr[st.top()]>=arr[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i]=(-1);
        } else {
            ans[i]=(arr[st.top()]);
        }
        st.push(i);
    }
    return ans;
}

signed main() {
    //code here
}