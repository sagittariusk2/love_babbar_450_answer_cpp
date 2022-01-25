/**
 * @file 35_sum_of_max_min_of_all_subarray_of_size_k
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-25
 * @time 12:47
 * @link https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
    deque<int> qmax, qmin;
    long long ans=0;
    for(int i=0; i<k; i++) {
        while(!qmax.empty() and arr[qmax.back()]<=arr[i]) {
            qmax.pop_back();
        }
        qmax.push_back(i);
        while(!qmin.empty() and arr[qmin.back()]>=arr[i]) {
            qmin.pop_back();
        }
        qmin.push_back(i);
    }
    ans += (arr[qmax.front()]+arr[qmin.front()]);
    for(int i=k; i<n; i++) {
        while(!qmax.empty() and i-qmax.front()==k) {
            qmax.pop_front();
        }
        while(!qmax.empty() and arr[qmax.back()]<=arr[i]) {
            qmax.pop_back();
        }
        qmax.push_back(i);
        while(!qmin.empty() and i-qmin.front()==k) {
            qmin.pop_front();
        }
        while(!qmin.empty() and arr[qmin.back()]>=arr[i]) {
            qmin.pop_back();
        }
        qmin.push_back(i);
        ans += (arr[qmax.front()]+arr[qmin.front()]);
    }
    return ans;
}


signed main() {
    //code here
}