/**
 * @file 34_segregate_even_and_odd_nodes_in_a_linked_list
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-08
 * @time 00:13
 * @link https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#
 * @copyright Copyright (c) 2022
 */


//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* even=nullptr, *odd=nullptr, *main=head, *x=nullptr, *y=nullptr;
        
        while(main) {
            if(main->data%2==0) {
                if(!even) x=main;
                if(even) {
                    even->next=main;
                }
                even=main;
            } else {
                if(!odd) y=main;
                if(odd) odd->next=main;
                odd=main;
            }
            main=main->next;
        }
        if(odd) {
            odd->next=nullptr;
        }
        if(even) {
            even->next=y;
        }
        if(x)
            return x;
        return y;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends