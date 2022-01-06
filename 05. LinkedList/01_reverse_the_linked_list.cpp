/**
 * Question Link :- (https://www.geeksforgeeks.org/reverse-a-linked-list/)
 * Reverse a linked list
 */




/**
 * ----@sagittarius_k2-----
 * Created by Ritesh Ranjan
 */

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

template<typename T>
struct Node {
    T data;
    struct Node* next;

    Node(T x) {
        data = x;
        next = nullptr;
    }

    Node(T x, struct Node* n) {
        data = x;
        next = n;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* solve(Node<T>* root) {
        if(!root or !root->next) return root;
        Node<T>* rest = solve(root->next);
        root->next->next = root;
        root->next = nullptr;
        return rest;
    }

public:
    Node<T>* head;

    LinkedList() {
        head = nullptr;
    }

    void print() {
        Node<T>* temp = head;
        while(head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n" ;
    }

    void create(T a[], int n) {
        Node<T>* temp = new Node<T>(a[0]);
        head = temp;
        for(int i=1; i<n; i++) {
            Node<T>* temp1 = new Node<T>(a[i]);
            temp->next = temp1;
            temp = temp1;
        }
    }

    void iterative_reverse() {
        if(head and head->next) {
            Node<T>* p = head->next;
            Node<T>* q = head;
            Node<T>* r = nullptr;
            while(q) {
                q->next = r;
                r = q;
                q = p;
                if(!q) break;
                p = p->next;
            }
            head = r;
        }
    }

    void recursive_reverse() {
        head = solve(head);
    }

};

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
        int nums[n];
		for(int i = 0; i < n; i++)
			cin >> nums[i];
        LinkedList<int> linkedList = LinkedList<int>();
        linkedList.create(nums, n);
        linkedList.recursive_reverse();
        linkedList.print();
	}
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(1)
 */
