/**
 * @file 24_rotate_DLL_by_n_nodes
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-07
 * @time 01:24
 * @link https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/
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
    Node* x=nullptr;
    while(head) {
        cout << head->data << " ";
        x = head;
        head = head->next;
    }
    cout << "\n";

    while(x) {
        cout << x->data << " ";
        x = x->prev;
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

Node* rotate(Node* head, int k) {
    Node* temp=head, *x=nullptr;
    while(k--) {
        x=temp;
        temp = temp->next;
    }

    Node* last=temp;
    while(last->next) {
        last=last->next;
    }
    x->next=nullptr;
    last->next=head;
    temp->prev = nullptr;
    head->prev=last;
    return temp;
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

    Node* ans=rotate(head, k);
    print_forward(ans);
}