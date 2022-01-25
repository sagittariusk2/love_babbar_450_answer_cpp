/**
 * @file 24_implement_n_queue_in_a_array
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 23:39
 * @link https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

class kQueue {
private:
    int *front, *rear, *next, *arr;
    int free;
public:
    kQueue(int n, int k) {
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        memset(front, -1, sizeof(front));
        free = 0;
        for(int i=0; i<k; i++) {
            next[i] = i+1;
        }
        next[n-1]=-1;
    }

    bool isFull() {
        return (free==-1);
    }

    bool isEmpty(int qn) {
        return (front[qn]==-1);
    }

    void push(int qn, int val) {
        if(isFull) {
            cerr << "\nQueue OverFlow\n";
            return;
        }
        int i=free;
        free = next[i];
        if(isEmpty(qn)) {
            front[qn] = i;
        } else {
            next[rear[qn]] = i;
        }
        next[i] = -1;
        rear[qn] = i;
        arr[i] = val;
    }

    void pop(int qn) {
        if(isEmpty(qn)) {
            cerr << "\nQueue UnderFlow\n";
            return ;
        }
        int i = front[qn];
        front[qn] = next[i];
        next[i] = free;
        free = i;
    }

    int front(int qn) {
        if(isEmpty(qn)) {
            cerr << "\nQueue Empty\n";
            return -1;
        } else {
            return arr[front[qn]];
        }
    }
};

signed main() {
    //code here
}