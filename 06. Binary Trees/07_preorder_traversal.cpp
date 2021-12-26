/**
 * Question Link :- (https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/)
 * Preorder Tree Traversal – Iterative and Recursive
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

void recursive_preorder(TreeNode* root) {
    if(root) {
        cout << root->val << " ";
        recursive_preorder(root->left);
        recursive_preorder(root->right);
    }
}

void iterative_preorder(TreeNode* root) {
    stack<TreeNode* > st;
    st.push(root);
    while(!st.empty()) {
        if(st.top()) {
            cout << st.top()->val <<" ";
            st.push(st.top()->left);
        } else {
            st.pop();
            if(!st.empty()) {
                TreeNode* temp = st.top();
                st.pop();
                st.push(temp->right);
            }
        }
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
    recursive_preorder(root);
    cout << "\n";
    iterative_preorder(root);
    cout << "\n";
}

/**
 * Time Complexity :- O(n)
 * Space Complexity :- O(n)
 */