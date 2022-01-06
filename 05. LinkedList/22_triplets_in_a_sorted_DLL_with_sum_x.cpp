/**
 * @file 22_triplets_in_a_sorted_DLL_with_sum_x
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-06
 * @time 17:03
 * @link https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
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

    int sum = 0;
    while(head) {
        Node *temp=head->next, *lTemp=tail;
        int ans = 0;
        while(temp and lTemp and temp!=lTemp) {
            if(temp->data+lTemp->data>k-head->data) {
                lTemp = lTemp->prev;
            } else if(temp->data+lTemp->data<k-head->data) {
                temp = temp->next;
            } else {
                ans++;
                temp = temp->next;
            }
        }
        head = head->next;
        sum += ans;
    }

    cout << sum << "\n";
}