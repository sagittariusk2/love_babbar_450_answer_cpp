/**
 * @file 31_merge_k_sorted_Linked_List
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-11
 * @time 15:58
 * @link https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
 * @copyright Copyright (c) 2022
 */


// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

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
private:
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
    int len(Node* head) {
        Node* x=head;
        int ans=0;
        while(x) {
            ans++;
            x = x->next;
        }
        return ans;
    }
public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K) {
        Node* ans = arr[0];
        int n=len(ans);
        for(int i=1; i<K; i++) {
            n += len(arr[i]);
            ans = merge(ans, arr[i], n);
        }
        return ans;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends