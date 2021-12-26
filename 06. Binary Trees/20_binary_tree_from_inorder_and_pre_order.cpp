/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/construct-tree-1/1)
 * Construct Binary tree from Inorder and preorder traversal
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
    int i;
    TreeNode* solve(int s, int e, int in[], int pre[], int n) {
        if(s>e or i==n) {
            return nullptr;
        }
        TreeNode* temp = new TreeNode(pre[i]);
        int x=-1;
        for(int j=s; j<=e; j++) {
            if(in[j]==pre[i]) {
                x = j;
                break;
            }
        }
        i++;
        temp->left = solve(s, x-1, in, pre, n);
        temp->right = solve(x+1, e, in, pre, n);
        return temp;
    }
public:
    TreeNode* buildTree(int in[],int pre[], int n) {
        i=0;
        TreeNode *ans = solve(0, n-1, in, pre, n);
        return ans;
    }

    void post_order(TreeNode* root) {
        if(root) {
            post_order(root->left);
            post_order(root->right);
            cout << root->val<<" ";
        }
    }
};

signed main() {
    int n;
    cin>>n;
    int in[n], pre[n];
    for(int i=0; i<n; i++) {
        cin >> in[i] ;
    }
    for(int i=0; i<n; i++) {
        cin >> pre[i] ;
    }

    Solution ob;
    TreeNode* root = ob.buildTree(in, pre, n);
    
    ob.post_order(root);
    cout << "\n";
}

/**
 * Time Complexity :- O(n*n)
 * Space Complexity :- O(n)
 */