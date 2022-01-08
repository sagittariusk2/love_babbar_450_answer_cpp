/**
 * @file 33_delete_nodes_which_have_a_greater_value_on_right_side
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-08
 * @time 00:57
 * @link https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#
 * @copyright Copyright (c) 2022
 */


#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
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

    Node *compute(Node *head) {
        Node* rev = reverse(head);
        Node* temp = rev->next, *ans=rev;
        ans->next=nullptr;
        while(temp) {
            if(temp->data>=ans->data) {
                ans->next=temp;
                ans=temp;
                temp=temp->next;
                ans->next=nullptr;
            } else {
                temp=temp->next;
            }
            
        }
        head=reverse(rev);
        return head;
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends