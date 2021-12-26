/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1)
 * Tree Isomorphism Problem
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
    TreeNode *ans;
    pair<bool, bool> solve(TreeNode* root, int n1, int n2) {
        if(root) {
            pair<bool, bool> temp1 = solve(root->left, n1, n2);
            pair<bool, bool> temp2 = solve(root->right, n1, n2);
            bool a=false, b=false;
            if(n1==root->val) a=true;
            if(n2==root->val) b=true;
            a = (a or temp1.first);
            a = (a or temp2.first);
            b = (b or temp1.second);
            b = (b or temp2.second);
            if(a and b and !ans) {
                ans=root;
            }
            return make_pair(a, b);
        }
    }
public:
    //Function to return the lowest common ancestor in a Binary Tree.
    TreeNode* lca(TreeNode* root ,int n1 ,int n2 ) {
        bool a = false;
        bool b = false;
        ans = nullptr;
        solve(root, n1, n2);
        
        // cout<<ans->data<<" ";
        return ans;
    }
};

signed main() {
    int n, n1, n2;
    cin>>n>>n1>>n2;
    vector<string> tree;
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        if(s=="NULL") i--;
        tree.push_back(s);
    }

    TreeNode* root1 = create_tree(tree);
    Solution ob;
    cout << ob.lca(root1, n1, n2)->val << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(h)
 */