/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1)
 * ZigZag Tree Traversal
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
public:
    //Function to store the zig zag order traversal of tree in a list.
    void solve(TreeNode* root, vector<vector<int>>&level, int h) {
        if(root) {
            if(level.size()==h) {
                vector<int> x;
                x.push_back(root->val);
                level.push_back(x);
            } else {
                level[h].push_back(root->val);
            }
            
            solve(root->left, level, h+1);
            solve(root->right, level, h+1);
        }
    }
    
    vector <int> zigZagTraversal(TreeNode* root) {
        vector<int> ans;
        vector<vector<int>> level;
        solve(root, level, 0);
        for(int i=0; i<level.size(); i++) {
            if(i%2) {
                for(int j=level[i].size()-1; j>=0; j--) {
                    ans.push_back(level[i][j]);
                }
            } else {
                for(auto j:level[i]) {
                    ans.push_back(j);
                }
            }
        }
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
    vector<int> ans = ob.zigZagTraversal(root);
    for(auto i:ans) {
        cout << i << " ";
    }
    cout << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(n)
 */