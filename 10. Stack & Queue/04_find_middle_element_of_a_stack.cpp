/*
    Question link :- (https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/)
    Question :- Design a stack with operations on middle element.
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

template <typename T>
struct Node {
    T val;
    Node *next;
    Node *back;
};

template <typename T>
class myStack {
private:
    int len;
    Node<T> *curr, *mid;

public:
    myStack();
    ~myStack();

    void push(T val);
    void pop();
    T top();
    T findMiddle();
    void deleteMiddle();
    bool isEmpty();
    int size();
    void print();
};

template <typename T>
void myStack<T>::print() {
    Node<T> *temp = curr;
    cout << "[";
    if(temp) cout << temp->val;
    temp=temp->back;
    while(temp) {
        cout << ", " << temp->val;
        temp = temp->back;
    }
    cout << "]" << endl;
}

template <typename T>
myStack<T>::myStack() {
    len = 0;
    curr = nullptr;
    mid = nullptr;
}

template <typename T>
myStack<T>::~myStack() {
    len = 0;
    curr = nullptr;
    mid = nullptr;
}

template <typename T>
void myStack<T>::push(T val) {
    len++;

    // Create a new Node with the value
    Node<T> *temp = new Node<T>;
    temp->val = val;
    temp->next = nullptr;
    temp->back = curr;

    if(curr) {
        curr->next = temp;
    }
    curr=temp;

    if(len%2==1) {

        if(len==1) mid=curr;
        else {
            mid = mid->next;
        }
    }

    // cout<<curr<<" "<<mid->next<<"\n";
}

template <typename T>
void myStack<T>::pop() {
    if(curr) {
        len--;
        curr = curr->back;
        if(curr) curr->next=nullptr;
        if(len%2==0) {
            mid=mid->back;
        }
    }
}

template <typename T>
T myStack<T>::top() {
    return curr->val;
}

template <typename T>
int myStack<T>::size() {
    return len;
}

template <typename T>
bool myStack<T>::isEmpty() {
    if(curr) return true;
    return false;
}

template <typename T>
T myStack<T>::findMiddle() {
    return mid->val;
}

template <typename T>
void myStack<T>::deleteMiddle() {
    if(len==1) {
        len--;
        curr=nullptr;
        mid=nullptr;
    } else if(len==2) {
        mid=curr;
        len--;
        curr->back=nullptr;
    } else {
        len--;
        Node<T> *p = mid->back;
        Node<T> *q = mid->next;
        p->next=q;
        q->back=p;
    }
}

signed main() {
    myStack<int> st;
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
    cout << st.findMiddle() << endl;
    st.print();
    st.deleteMiddle();
    st.print();
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/