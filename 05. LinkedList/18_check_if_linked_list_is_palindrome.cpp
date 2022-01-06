/**
 * @file 18_check_if_linked_list_is_palindrome.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    
private:
    Node* reverse(Node* head) {
        if(head) {
            Node *p=head, *r=head->next, *q=nullptr;
            while(p) {
                p->next=q;
                q=p;
                p=r;
                if(r) r=r->next;
            }
            return q;
        }
        return nullptr;
    }
    
public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        
        //Divide List into 2 halves
        Node *slow=head, *fast=head, *pre=nullptr;
        while(fast and fast->next) {
            if(fast->next)
                fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        
        if(pre==nullptr) return true;
        
        pre->next=nullptr;
        slow=reverse(slow);
        
        while(slow and head) {
            if(slow->data!=head->data) return false;
            slow=slow->next;
            head=head->next;
        }
        
        return true;
        
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends