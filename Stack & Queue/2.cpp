/*
    Question link :- (https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/)
    Question :- Implementation Of Queue using node data structure.
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
};

template <typename T>
class myQueue {
private:
    int len;
    Node<T> *f, *b;

public:
    myQueue();
    ~myQueue();

    void push(T val);
    void pop();
    T front();
    T back();
    bool isEmpty();
    int size();
};

template <typename T>
myQueue<T>::myQueue() {
    len = 0;
    f = nullptr;
    b = nullptr;
}

template <typename T>
myQueue<T>::~myQueue() {
    f = nullptr;
    b = nullptr;
    len = 0;
}

template <typename T>
void myQueue<T>::push(T val) {
    len++;

    // Create a new Node with the value
    Node<T> *temp = new Node<T>;
    temp->val = val;
    temp->next = nullptr;

    if(b) b->next = temp;
    if(!f) f = temp;
    b = temp;
}

template <typename T>
void myQueue<T>::pop() {
    if(f) {
        len--;
        f = f->next;
        if(!f) b = f;
    }
}

template <typename T>
T myQueue<T>::front() {
    return f->val;
}

template <typename T>
T myQueue<T>::back() {
    return b->val;
}

template <typename T>
int myQueue<T>::size() {
    return len;
}

template <typename T>
bool myQueue<T>::isEmpty() {
    if(len) return true;
    return false;
}

signed main() {
    myQueue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    cout<<qu.back()<<" "<<qu.front()<<"\n";
    qu.pop();
    cout<<qu.back()<<" "<<qu.front()<<"\n";
    qu.pop();
    cout<<qu.back()<<" "<<qu.front()<<"\n";
    qu.pop();
    cout<<qu.size()<<"\n";
    qu.pop();
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/