/**
 * Question Link :- (https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/#:~:text=Given%20the%20array%20representation%20of,it%20into%20Binary%20Search%20Tree.&text=Swap%201%3A%20Swap%20node%208,node%209%20with%20node%2010.)
 * Find minimum swaps required to convert a Binary tree into BST
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
    int solve(vector<int>&in) {
        vector<pair<int, int>> v1;
        for(int i=0; i<in.size(); i++) {
            v1.emplace_back(in[i], i);
        }
        sort(v1.begin(), v1.end());
        vector<bool> vis(in.size(), true);
        int ans=0;
        for(int i=0; i<v1.size(); i++) {
            int x = 1;
            vis[i]=false;
            int j=v1[i].second;
            while(vis[j]) {
                vis[j]=false;
                j = v1[j].second;
                x++;
            }
            ans += (x-1);
        }
        return ans;
    }

    void inorder(TreeNode* root, vector<int>&in) {
        if(root) {
            inorder(root->left, in);
            in.push_back(root->val);
            inorder(root->right, in);
        }
    }
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int to_BST(TreeNode *node) {
        vector<int> in;
        inorder(node, in);
        return solve(in);
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
    cout << ob.to_BST(root) << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(h)
 */