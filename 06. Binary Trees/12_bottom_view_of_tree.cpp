/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)
 * Bottom view of a tree
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
    void solve(map<int, pair<int, int>> &mp, TreeNode* root, int d, int h) {
        if(root) {
            if((mp.find(d)!=mp.end() and mp[d].second<=h) or mp.find(d)==mp.end()) {
                mp[d]=make_pair(root->val, h);
            }
            solve(mp, root->left, d-1, h+1);
            solve(mp, root->right, d+1, h+1);
        }
    }
public:
    vector <int> bottomView(TreeNode *root) {
        map<int, pair<int, int>> mp;
        solve(mp, root, 0, 0);
        vector<int> ans;
        for(auto i:mp) 
            ans.push_back(i.second.first);
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
    vector<int> ans = ob.bottomView(root);
    for(auto i:ans) {
        cout << i << " ";
    }
    cout << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(n)
 */