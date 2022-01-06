/**
 * @file 15_middle_of_the_linked_list.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *ptr1, *ptr2;
        ptr1=head, ptr2=head;
        while(ptr2!=nullptr) {
            ptr2=ptr2->next;
            if(ptr2==nullptr) return ptr1;
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
        return ptr1;
    }
};