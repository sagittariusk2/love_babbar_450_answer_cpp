/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1)
 * Check if all leaf nodes are at same level or not
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
    int height=-1;
    bool ans=true;
    void solve(TreeNode* root, int h) {
        if(root) {
            if(!root->left and !root->right) {
                if(height==-1)
                    height=max(height, h);
                else {
                    if(height!=h) ans=false;
                }
            }
            solve(root->left, h+1);
            solve(root->right, h+1);
        }
    }

public:
    /*You are required to complete this method*/
    bool check(TreeNode *root) {
        solve(root, 0);
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
    cout << ob.check(root) << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(h)
 */