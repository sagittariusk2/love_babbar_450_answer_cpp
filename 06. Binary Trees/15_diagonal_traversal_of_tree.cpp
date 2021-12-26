/**
 * Question Link :- (https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/)
 * Diagonal Traversal of a tree
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
    void solve(TreeNode* root, int d, vector<vector<int>> &ans) {
        if(root) {
            if(ans.size()==d) {
                vector<int> x;
                x.push_back(root->val);
                ans.push_back(x);
            } else {
                ans[d].push_back(root->val);
            }
            solve(root->left, d+1, ans);
            solve(root->right, d, ans);
        }
    }
public:
    vector<vector<int>> diagonal_traversal(TreeNode *root) {
        vector<vector<int>> ans;
        solve(root, 0, ans);
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

    TreeNode* root = create_tree(tree);
    Solution ob;
    vector<vector<int>> ans = ob.diagonal_traversal(root);
    for(auto i:ans) {
        for(auto j:i) 
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(n)
 */