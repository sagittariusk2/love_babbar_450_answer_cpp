/**
 * @file 19_deletion_from_a_circular_linked_list
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-06
 * @time 15:34
 * @link https://www.geeksforgeeks.org/deletion-circular-linked-list/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next=nullptr;
    }
};

Node* removeNode(Node* head, Node* p) {
    Node* temp=head;
    
    while(temp->next!=p) {
        temp = temp->next;
    }
    temp->next=p->next;
    if(head==p) {
        if(head->next==head) return nullptr;
        else return head->next;
    }
    return head;
}

void print(Node* head) {
    Node* temp=head;
    cout << temp->data << " ";
    temp=temp->next;
    while(temp!=head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

signed main() {
    int n, x;
    cin >> n;
    struct Node* temp, *head, *q;
    cin >> x;
    head = new Node(x);
    temp=head;
    n--;
    while(n--) {
        cin >> x;
        Node* y = new Node(x);
        temp->next=y;
        temp=y;
        if(n==2) q=y;
    }

    temp->next=head;

    print(head);

    Node* r_head = removeNode(head, q);

    print(r_head);
}