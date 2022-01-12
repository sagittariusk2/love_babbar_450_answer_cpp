/**
 * @file 30_print_all_k_sum_paths_in_a_binary_tree
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-12
 * @time 00:48
 * @link https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
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

vector<vector<int>> ans;

void solve(TreeNode* root, vector<int> v1, int k) {
    if(root) {
        v1.push_back(root->data);
        int sum = 0, n=v1.size();
        for(int i=n-1; i>=0; i--) {
            sum += v1[i];
            if(sum==k) {
                vector<int> x;
                for(int j=i; j<n; j++) {
                    x.push_back(v1[j]);
                }
                ans.push_back(x);
            }
        }
        solve(root->left, v1, k);
        solve(root->right, v1, k);
    }
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

    int k;
    cin >> k;

    TreeNode* root = create_tree(tree);
    vector<int> v1;
    solve(root, v1, k);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}