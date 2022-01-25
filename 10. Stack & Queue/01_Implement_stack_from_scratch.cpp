/*
    Question link :- (https://www.tutorialspoint.com/javaexamples/data_stack.htm)
    Question :- Implementation Of Stack using node data structure.
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
    Node<T> *curr;

public:
    myStack();
    ~myStack();

    void push(T val);
    void pop();
    T top();
    bool isEmpty();
    int size();
};

template <typename T>
myStack<T>::myStack() {
    len = 0;
    curr = nullptr;
}

template <typename T>
myStack<T>::~myStack() {

}

template <typename T>
void myStack<T>::push(T val) {
    len++;

    // Create a new Node with the value
    Node<T> *temp = new Node<T>;
    temp->val = val;
    temp->next = nullptr;
    temp->back = curr;

    if(curr && curr->next) curr->next = temp;
    curr=temp;
}

template <typename T>
void myStack<T>::pop() {
    if(curr) {
        len--;
        Node<T> *temp = curr->back;
        if(curr->back) curr->back->next = nullptr;
        curr = temp;
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

signed main() {
    myStack<string> st;
    st.push("Janhavi");
    st.push("Ritesh");
    st.push("Lucky");
    cout<<st.top()<<" "<<st.size()<<"\n";
    st.pop();
    cout<<st.top()<<" "<<st.size()<<"\n";
    st.pop();
    cout<<st.top()<<" "<<st.size()<<"\n";
    st.pop();
    st.pop();
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/
