/**
 * @file 05_implementation_of_k_stack_in_an_array
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 23:40
 * @link https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

class kStacks {
private:
    int *arr, *top, *next;
    int free;
public:
    kStacks(int n, int k) {
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        memset(top, -1, sizeof(top));
        for(int i=0; i<n; i++) {
            next[i]=i+1;
        }
        next[n-1]=-1;
        free = 0;
    }

    void push(int st, int x) {
        if(isFull()) {
            cerr << "\nStack Overflow\n";
            return ;
        }
        int i = free;
        free = next[i];
        next[i]=top[st];
        top[st]=i;
        arr[i]=x;
    }

    void pop(int st) {
        int i=top[st];
        top[st]=next[i];
        next[i]=free;
        free=i;
    }

    bool isFull() {
        return (free==-1);
    }

    bool isEmpty() {
        return (free==0);
    }

    int top(int st) {
        return arr[top[st]];
    }
};

signed main() {
    //code here
}