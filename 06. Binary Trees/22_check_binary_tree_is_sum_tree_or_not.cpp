/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/sum-tree/1)
 * Check if Binary tree is Sum tree or not
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
    bool ans=true;
    int solve(TreeNode* root) {
        if(root) {
            int x = solve(root->left);
            int y = solve(root->right);
            if(x==0 and y==0);
            else if(x==0 and y!=root->val) ans = false;
            else if(y==0 and x!=root->val) ans = false;
            else if(x+y!=root->val) {
                ans = false;
            }
            return x+y+root->val;
        }
        return 0;
    }
public:
    bool isSumTree(TreeNode* root) {
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

    TreeNode* root = create_tree(tree);
    Solution ob;
    cout << ob.isSumTree(root) << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(h)
 */