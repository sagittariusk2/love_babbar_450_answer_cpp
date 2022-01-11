/**
 * @file 23_sort_a_k_sorted_DLL
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-07
 * @time 01:36
 * @link https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
    Node(int x) {
        data=x;
        next=prev=nullptr;
    }
};

void print_forward(Node* x) {
    Node* head = x;
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

signed main() {
    int n, x, k;
    cin >> n >> k;
    Node* head, *tail;
    cin >> x;
    head = new Node(x);
    tail = head;
    n--;
    while(n--) {
        cin >> x;
        Node* y=new Node(x);
        tail->next = y;
        y->prev = tail;
        tail = y;
    }

    priority_queue<int, vector<int>> pq;
    Node* p = head, *q = head;
    k++;
    while(k--) {
        pq.push(-q->data);
        q = q->next;
    }
    while(p) {
        p->data = -pq.top();
        p = p->next;
        pq.pop();
        if(q) {
            pq.push(-q->data);
            q = q->next;
        }
    }
    print_forward(head);
}