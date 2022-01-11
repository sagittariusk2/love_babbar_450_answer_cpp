/**
 * @file 14_quick_sort_in_linked_list
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-11
 * @time 15:01
 * @link https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1
 * @copyright Copyright (c) 2022
 */


#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

int len(node* head) {
    node *x=head;
    int ans=0;
    while(x) {
        ans++;
        x = x->next;
    }
    return ans;
}

void solve(struct node* head) {
    node* temp = head->next;
    int pivot = head->data;
    int n = len(head);
    if(n==1) return ;
    n--;
    int a[n], i=0, j=n-1;
    while(temp) {
        if(temp->data > pivot) {
            a[j--]=temp->data;
        } else {
            a[i++] = temp->data;
        }
        temp = temp->next;
    }
    node* mid = head;
    temp=head->next;
    i=0;
    while(temp) {
        temp->data = a[i++];
        temp = temp->next;
    }
    if(j==-1) {
        solve(head->next);
        return;
    }
    while(j--) {
        mid = mid->next;
    }
    if(mid->next) {
        swap(mid->next->data, head->data);
        node* x = mid->next;
        mid->next=nullptr;
        solve(head);
        if(x)
            solve(x);
        mid->next=x;
    }
}


//you have to complete this function
void quickSort(struct node **headRef) {
    node *head = *headRef;
    solve(head);
}