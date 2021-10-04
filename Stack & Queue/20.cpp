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
    myStack() {
        len = 0;
        curr = nullptr;
    }

    ~myStack() {

    }

    void push(T val) {
        len++;

        // Create a new Node with the value
        Node<T> *temp = new Node<T>;
        temp->val = val;
        temp->next = nullptr;
        temp->back = curr;

        if(curr && curr->next) curr->next = temp;
        curr=temp;
    }
    
    void pop() {
        if(curr) {
            len--;
            Node<T> *temp = curr->back;
            if(curr->back) curr->back->next = nullptr;
            curr = temp;
        }
    }

    T top() {
        return curr->val;
    }

    bool isEmpty() {
        if(curr) return true;
        return false;
    }

    int size() {
        return len;
    }
};

template <typename T>
class myQueue {
private:
    myStack<T> st1, st2;

public:
    myQueue() {
        
    }

    ~myQueue() {

    }

    void push(T val) {
        if(st1.isEmpty()) {
            st2.push(val);
            cout<<st2.top()<<"\n";
        }
        else st1.push(val);
    }

    void pop() {
        if(st2.isEmpty()) {
            while(!st1.isEmpty()) {
                T temp = st1.top();
                st1.pop();
                st2.push(temp);
            }
            st2.pop();
        } else {
            while(!st2.isEmpty()) {
                T temp = st2.top();
                st2.pop();
                st1.push(temp);
            }
            st1.pop();
        }
    }

    T front() {
        if(st2.isEmpty()) {
            while(!st1.isEmpty()) {
                T temp = st1.top();
                st1.pop();
                st2.push(temp);
            }
            return st2.top();
        } else {
            while(!st2.isEmpty()) {
                T temp = st2.top();
                st2.pop();
                st1.push(temp);
            }
            return st1.top();
        }
    }

    T back() {
        if(st1.isEmpty()) return st2.top();
        else return st1.top();
    }

    bool isEmpty() {
        return (st1.isEmpty() and st2.isEmpty());
    }

    int size() {
        if(st1.isEmpty()) return st2.size();
        else return st1.size();
    }
};

signed main() {
    myQueue<int> q1;
    q1.push(1);
    q1.push(3);
    q1.push(5);
    // cout<<q1.isEmpty();
    // while (!q1.isEmpty())
    // {
    //     cout<<q1.front()<<" ";
    //     q1.pop();
    // }
    
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(n)
*/