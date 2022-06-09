/**
 * @file 01_Binary_Search_Tree
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-04-23
 * @time 12:14
 * @link https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Binary_Search_Tree {
private:
    Node *root;
    void solve(Node *tree) {
        if(tree) {
            solve(tree->left);
            cout << tree->val << " ";
            solve(tree->right);
        }
    }
public:
    Binary_Search_Tree() {
        root = nullptr;
    }

    void insert(int x) {
        if(root == nullptr) {
            root = new Node(x);
        } else {
            Node *temp = root;
            Node *temp_par = nullptr;
            while(temp) {
                temp_par = temp;
                if(temp->val>x) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
            if(temp_par->val>x) temp_par->left = new Node(x);
            else temp_par->right = new Node(x);
        }
    }

    bool search(int x) {
        Node*temp = root;
        while(temp) {
            if(temp->val == x) {
                return true;
            } else if(temp->val < x) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        return false;
    }

    void inorder() {
        Node *temp = root;
        solve(temp);
        cout << endl;
    }
};

signed main() {
    Binary_Search_Tree bst;
    bst.insert(10);
    bst.insert(12);
    bst.insert(5);
    bst.insert(11);
    bst.insert(2);
    bst.insert(15);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.inorder();
    if(bst.search(10)) cout << "Found" << endl;
    if(bst.search(18)) cout << "Found" << endl;
}