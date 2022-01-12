/**
 * @file 28_largest_sub_tree_sum_in_a_tree
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-12
 * @time 10:42
 * @link link
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

int ans=0;

int solve(TreeNode* root) {
    if(root) {
        int x = solve(root->left)+solve(root->right)+root->data;
        ans = max(ans, x);
        return x;
    }
    return 0;
}

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

    solve(root);
    cout << ans << endl;
}