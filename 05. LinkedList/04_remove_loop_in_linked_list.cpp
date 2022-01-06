/**
 * @file 04_remove_loop_in_linked_list.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        struct Node *slow=head, *fast=head;
        while(fast and fast->next) {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) {
                break;
            }
        }
        
        // If cycle is detected
        if(fast==slow) {
            // count the number of nodes in cycle
            int k=1;
            while(slow->next!=fast) {
                slow = slow->next;
                k++;
            }
            
            // Get kth node in the linkedlist
            struct Node* kthNode=head, *pre=nullptr;
            while(k--) {
                pre = kthNode;
                kthNode = kthNode->next;
            }
            
            struct Node* temp=head;
            while(temp!=kthNode) {
                pre = kthNode;
                kthNode = kthNode->next;
                temp = temp->next;
            }
            pre->next=nullptr;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends