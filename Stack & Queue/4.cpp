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
};

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
        curr->back = temp;
    }
    curr=temp;

    if(len%2==1) {

        if(len==1) mid=curr;
        else {
            mid = mid->next;
        }
    }

    cout<<curr<<" "<<mid->next<<"\n";
}

template <typename T>
void myStack<T>::pop() {
    if(curr) {
        len--;
        Node<T> *temp = curr->back;
        if(curr->back) curr->back->next = nullptr;
        curr = temp;
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
    
}

signed main() {
    myStack<string> st;
    st.push("Janhavi");
    // cout<<st.findMiddle()<<"\n";
    st.push("Ritesh");
    // cout<<st.findMiddle()<<"\n";
    st.push("Lucky");
    // cout<<st.findMiddle()<<"\n";
    st.push("Manvir");
    // cout<<st.findMiddle()<<"\n";
    st.push("Rahul");
    // cout<<st.findMiddle()<<"\n";
    st.push("Chhote Lal");
    // cout<<st.findMiddle()<<"\n";
    st.push("Manhar");
    // cout<<st.findMiddle()<<"\n";
    // cout<<st.top()<<" "<<st.size()<<"\n";
    // st.pop();
    // cout<<st.top()<<" "<<st.size()<<"\n";
    // st.pop();
    // cout<<st.top()<<" "<<st.size()<<"\n";
    // st.pop();
    // st.pop();
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/