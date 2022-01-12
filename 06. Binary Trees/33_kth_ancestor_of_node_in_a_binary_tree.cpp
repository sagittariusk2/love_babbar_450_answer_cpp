/**
 * @file 33_kth_ancestor_of_node_in_a_binary_tree
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-12
 * @time 19:48
 * @link https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
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

void inorder(TreeNode *root) {
    if(root) {
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

class Solution {
private:
    bool found = false;
    int x, k, ans=-1;

    int solve(TreeNode* root) {
        if(root) {
            if(root->data==x) return 1;
            int a = solve(root->left);
            int b = solve(root->right);
            int a1 = max(a, b);
            if(a1==k) ans = root->data;
            if(a1==-1) return -1;
            return a1+1;
        }
        return -1;
    }
public:
    int kthAncestor(TreeNode* root, int x, int k) {
        if(k==0) return x;
        this->x = x;
        this->k = k;
        found = false;
        solve(root);
        return ans;
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

    int k;
    cin >> k;

    TreeNode* root = create_tree(tree);

    Solution ob;
    cout << ob.kthAncestor(root, 5, k) << endl;
}