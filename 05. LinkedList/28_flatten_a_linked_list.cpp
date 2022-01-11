/**
 * @file 28_flatten_a_linked_list
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-11
 * @time 17:53
 * @link https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node* head1, Node* head2) {
    if(head1==nullptr) return head2;
    if(head2==nullptr) return head1;
    Node* ans = nullptr, *p=head1, *q = head2, *temp;
    if(head1->data<head2->data) {
        ans = head1;
        p = head1->bottom;
    } else {
        ans = head2;
        q = head2->bottom;
    }
    temp=ans;
    while(p and q) {
        if(p->data<q->data) {
            ans->bottom = p;
            p = p->bottom;
            ans = ans->bottom;
        } else {
            ans->bottom = q;
            q = q->bottom;
            ans = ans->bottom;
        }
    }
    if(p) {
        ans->bottom=p;
    }
    if(q) {
        ans->bottom=q;
    }
    return temp;
}    

Node *flatten(Node *root) {
    Node* ans=root;
    root=root->next;
    while(root) {
        ans = merge(ans, root);
        root = root->next;
    }
    return ans;
}

