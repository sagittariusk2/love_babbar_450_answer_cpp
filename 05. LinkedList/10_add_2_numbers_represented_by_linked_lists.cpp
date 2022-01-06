/**
 * @file -2_numbers_represented_by_linked_lists.cpp
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

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node* head) {
        if(head) {
            Node *p=head->next, *q=head, *pre=nullptr;
            while(q) {
                q->next = pre;
                pre = q;
                q = p;
                if(p)
                    p = p->next;
            }
            return pre;
        }
        return head;
    }
    
    Node* add(struct Node* first, struct Node* second, int c) {
        if(first and second) {
            first->data = first->data+second->data+c;
            if(first->data>=10) {
                first->data %= 10;
                first->next = add(first->next, second->next, 1);
            } else {
                first->next = add(first->next, second->next, 0);
            }
            return first;
        } else if(first) {
            first->data = first->data+c;
            if(first->data>=10) {
                first->data %= 10;
                first->next = add(first->next, nullptr, 1);
            } else {
                first->next = add(first->next, nullptr, 0);
            }
            return first;
        } else if(second) {
            second->data = second->data+c;
            if(second->data>=10) {
                second->data %= 10;
                second->next = add(nullptr, second->next, 1);
            } else {
                second->next = add(nullptr, second->next, 0);
            }
            return second;
        } else {
            if(c) {
                Node* temp = new Node(1);
                return temp;
            }
            return nullptr;
        }
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* f = reverse(first);
        Node* s = reverse(second);
        
        Node* ans=add(f, s, 0);
        
        ans = reverse(ans);
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends