/**
 * @file 21_pairs_with_given_sum_in_DLL
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-06
 * @time 16:41
 * @link https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
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

void print_forward(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void print_reverse(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->prev;
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

    while(head and tail and head!=tail) {
        if(head->data+tail->data>k) {
            tail = tail->prev;
        } else if(head->data+tail->data<k) {
            head = head->next;
        } else {
            cout << "(" << head->data << ", " << tail->data << ") ";
            head = head->next;
        }
    }
}