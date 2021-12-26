/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1)
 * Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]
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
    int ans=0;
    set<string> s1;
    string solve(TreeNode* root) {
        if(root) {
            string x = solve(root->left);
            string y = solve(root->right);
            string z=to_string(root->val);
            if(!x.empty())
                z+=("("+x+")");
            if(!y.empty())
                z+=("("+y+")");
            if(z.find("(")!=string::npos and s1.find(z)!=s1.end()) {
                ans=1;
            }
            s1.insert(z);
            return z;
        }
        return "";
    }
public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(TreeNode *root) {
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
    cout << ob.dupSub(root) << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(h)
 */