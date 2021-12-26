/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1)
 * Convert Binary tree into Doubly Linked List
 */

/**
 * ----@sagittarius_k2-----
 * Created by Ritesh Ranjan
 */

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int n) {
        val = n;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int n, TreeNode* left, TreeNode* right) {
        val = n;
        this->left = left;
        this->right = right;
    }
};

TreeNode* create_tree(vector<string> &tree) {
    if(tree.size()==0 or tree[0]=="NULL") return nullptr;
    TreeNode* root = new TreeNode(stoi(tree[0]));
    int n = tree.size();
    queue<TreeNode*> q1;
    q1.push(root);
    int x=0;
    for(int i=1; i<n; i++) {
        if(x%2==0) {
            if(tree[i]!="NULL") {
                q1.front()->left = new TreeNode(stoi(tree[i]));
                q1.push(q1.front()->left);
            }
        } else {
            if(tree[i]!="NULL") {
                q1.front()->right = new TreeNode(stoi(tree[i]));
                q1.push(q1.front()->right);
            }
            q1.pop();
        }
        x++;
    }
    return root;
}

class Solution {
private:
    TreeNode* a, *ans;
    void solve(TreeNode* root) {
        if(root) {
            solve(root->left);
            if(a) {
                a->right=root;
            } else {
                ans = root;
            }
            root->left = a;
            a = root;
            solve(root->right);
        }
    }
public: 
    //Function to convert binary tree to doubly linked list and return it.
    TreeNode * bToDLL(TreeNode *root) {
        a = nullptr;
        ans = nullptr;
        solve(root);
        return ans;
    }

    void print(TreeNode* root) {
        TreeNode* temp = root;
        while(temp) {
            cout << root->val << " ";
            if(!temp->right) {
                cout << "\n";
                break;
            }
            temp = temp->right;
        }
        while(temp) {
            cout << root->val << " ";
            temp = temp->left;
        }
        cout << "\n";
    }
};

signed main() {
    int n;
    cin>>n;
    vector<string> tree;
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        if(s=="NULL") i--;
        tree.push_back(s);
    }

    TreeNode* root = create_tree(tree);
    Solution ob;
    TreeNode* ans = ob.bToDLL(root);
    ob.print(ans);
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(h)
 */