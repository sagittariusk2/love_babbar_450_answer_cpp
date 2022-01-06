/**
 * @file 25_reverse_a_DLL_in_group_of_k
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-07
 * @time 00:44
 * @link https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
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

Node* reverse(Node* head, int k, Node* p) {
    if(!head) return nullptr;
    int x = k;
    Node* ans=head, *q=nullptr;
    while(x-- and ans) {
        swap(ans->next, ans->prev);
        q=ans;
        ans = ans->prev;
    }
    if(q)
        q->prev = p;
    head->next = reverse(ans, k, head);
    return q;
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
    
    Node* ans=reverse(head, k, nullptr);
    print_forward(ans);
}