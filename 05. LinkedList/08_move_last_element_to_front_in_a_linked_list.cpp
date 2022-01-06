/**
 * @file 08_move_last_element_to_front_in_a_linked_list.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

void print(Node* temp) {
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node* moveLastToFirst(Node* head) {
    struct Node* p=head, *q=nullptr;
    while(p->next!=nullptr) {
        q=p;
        p=p->next;
    }
    q->next=nullptr;
    p->next=head;
    head=p;
    return head;
}

int main() {
    int n;
    cin >> n;
    struct Node* head;
    int x;
    cin >> x;
    head = new Node(x);
    struct Node *temp = head;
    for(int i=0; i<n-1; i++) {
        cin >> x;
        struct Node* c = new Node(x);
        temp->next = c;
        temp = c;
    }

    struct Node* ans=moveLastToFirst(head);
    print(ans);
}