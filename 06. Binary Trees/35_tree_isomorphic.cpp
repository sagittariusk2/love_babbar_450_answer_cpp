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
public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(TreeNode *root1, TreeNode *root2) {
        if(root1 and root2) {
            bool x, y;
            x = isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right);
            y = isIsomorphic(root1->left, root2->right) and isIsomorphic(root1->right, root2->left);
            if(root1->val==root2->val) {
                return (x or y);
            }
            return false;
        }
        if(!root1 and !root2) {
            return true;
        }
        return false;
    }
};

signed main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<string> tree1, tree2;
    for(int i=0; i<n1; i++) {
        string s;
        cin>>s;
        if(s=="NULL") i--;
        tree1.push_back(s);
    }

    for(int i=0; i<n2; i++) {
        string s;
        cin>>s;
        if(s=="NULL") i--;
        tree2.push_back(s);
    }

    TreeNode* root1 = create_tree(tree1);
    TreeNode* root2 = create_tree(tree2);
    Solution ob;
    cout << ob.isIsomorphic(root1, root2) << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(h)
 */