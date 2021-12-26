/**
 * Question Link :- (https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/)
 * Construct Binary Tree from String with bracket representation
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

TreeNode* create_tree(string s) {
    cout << s << "\n";
    int n=s.length(), i=0;
    string v;
    while(i<n and s[i]!='(' and s[i]!=')') {
        v += s[i++];
    }

    TreeNode* root = new TreeNode(stoi(v));
    stack<char> st;
    if(s[i]=='(') st.push('(');
    i++;
    int start = i;
    while(i<n and !st.empty()) {
        if(s[i]=='(') {
            st.push('(');
        } else if(s[i]==')') {
            st.pop();
        }
        i++;
    }
    int l1 = i-start-1;
    if(l1>0)
        root->left = create_tree(s.substr(start, l1));
    int l2 = n-(l1+start+3);
    if(l2>0)
        root->right = create_tree(s.substr(i+1, l2));
    return root;
}

void recursive_inorder(TreeNode* root) {
    if(root) {
        recursive_inorder(root->left);
        cout << root->val << " ";
        recursive_inorder(root->right);
    }
}

signed main() {
    string s;
    cin >> s;

    TreeNode* root = create_tree(s);
    recursive_inorder(root);
    cout << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(n)
 */