/**
 * @file 21_implement_stack_using_deque
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 23:22
 * @link https://www.geeksforgeeks.org/implement-stack-queue-using-deque/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

class stack_from_deque {
private:
    deque<int> qu;
public:
    void push(int x) {
        qu.push_back(x);
    }

    void pop() {
        qu.pop_back();
    }

    int top() {
        return qu.back();
    }

    bool empty() {
        return qu.empty();
    }
};

class queue_from_deque {
private:
    deque<int> qu;
public:
    void push(int x) {
        qu.push_back(x);
    }

    void pop() {
        qu.pop_front();
    }

    int front() {
        return qu.front();
    }

    bool empty() {
        return qu.empty();
    }
};

signed main() {
    //code here
}