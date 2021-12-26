/**
 * Question Link :- (https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1)
 * Find all Duplicate subtrees in a Binary tree [ IMP ]
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

string solve(TreeNode* root, vector<TreeNode*> &ans, map<string, TreeNode*> &mp) {
        if(root) {
            string x = solve(root->left, ans, mp);
            string y = solve(root->right, ans, mp);
            string z=to_string(root->val);
            if(!x.empty())
                z+=("("+x+")");
            if(!y.empty())
                z+=("("+y+")");
            if(mp.find(z)!=mp.end()) {
                if(mp[z]) {
                    ans.push_back(root);
                    mp[z] = nullptr;
                }
            } else {
                mp[z]=root;
            }
            return z;
        }
        return "";
    }
vector<TreeNode*> printAllDups(TreeNode* root) {
    vector<TreeNode*> ans;
    map<string, TreeNode*> mp;
    solve(root, ans, mp);
    return ans;
}

void print(TreeNode* root) {
    if(root) {
        print(root->left);
        cout << root->val;
        print(root->right);
    }
}

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
    vector<TreeNode*> ans = printAllDups(root);
    for(auto i:ans) {
        print(i);
        cout << "\n";
    }
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(n)
 */