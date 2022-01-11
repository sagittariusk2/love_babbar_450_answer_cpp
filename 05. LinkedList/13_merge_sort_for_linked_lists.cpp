/**
 * @file 13_merge_sort_for_linked_lists
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-11
 * @time 11:09
 * @link https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
 * @copyright Copyright (c) 2022
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution {
private:
    int len(Node* head) {
        Node* x = head;
        int ans=0;
        while(x) {
            ans++;
            x = x->next;
        }
        return ans;
    }
    
    Node* merge(Node* head1, Node* head2, int n) {
        int a[n], i=0;
        Node* temp1=head1, *temp2=head2, *pre=nullptr;
        while(temp1 and temp2) {
            if(temp1->data<temp2->data) {
                a[i++]=temp1->data;
                temp1 = temp1->next;
            } else {
                a[i++]=temp2->data;
                temp2 = temp2->next;
            }
        }
        while(temp1) {
            a[i++]=temp1->data;
            temp1 = temp1->next;
        }
        while(temp2) {
            a[i++]=temp2->data;
            temp2 = temp2->next;
        }
        temp1=head1, temp2=head2;
        for(int j=0; j<n; j++) {
            if(temp1) {
                pre=temp1;
                temp1->data=a[j];
                temp1=temp1->next;
            } else {
                temp2->data=a[j];
                temp2=temp2->next;
            }
        }
        pre->next=head2;
        return head1;
    }
    
public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        int n=len(head);
        int m=n/2;
        Node* mid = head, *pre = nullptr;
        while(m--) {
            pre = mid;
            mid = mid->next;
        }
        if(pre!=nullptr) {
            pre->next = nullptr;
            head = mergeSort(head);
            mid = mergeSort(mid);
            head = merge(head, mid, n);
            return head;
        }
        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends