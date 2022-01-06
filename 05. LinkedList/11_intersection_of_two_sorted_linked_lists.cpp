/**
 * @file 10_intersection_of_two_sorted_linked_lists.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2) {
    Node* p=head1, *q=head2, *ans=nullptr, *temp;
    while(p and q) {
        if(p->data>q->data) {
            q = q->next;
        } else if(p->data<q->data) {
            p = p->next;
        } else {
            if(!ans) {
                ans = p;
                temp=p;
            } else {
                ans->next=p;
                ans=p;
            }
            p = p->next;
            q = q->next;
        }
    }
    if(ans)
    ans->next=nullptr;
    // while(temp) {
    //     cout << temp->data << " ";
    //     temp= temp->next;
    // }
    // cout << "\n";
    return temp;
}