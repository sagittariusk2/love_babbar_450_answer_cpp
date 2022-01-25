/**
 * @file 34_check_if_all_levels_of_two_trees_are_anagrams_or_not
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-25
 * @time 13:36
 * @link https://www.geeksforgeeks.org/check-if-all-levels-of-two-trees-are-anagrams-or-not/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>
    class TreeNode {
    public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

bool solve(vector<TreeNode<int>*> &v1, vector<TreeNode<int>*> &v2) {
    vector<TreeNode<int>*> nv1, nv2;
    vector<int> nums1, nums2;
    for(auto i:v1) {
        nums1.push_back(i->val);
        if(i->left) nv1.push_back(i->left);
        if(i->right) nv1.push_back(i->right);
    }
    for(auto i:v2) {
        nums2.push_back(i->val);
        if(i->left) nv2.push_back(i->left);
        if(i->right) nv2.push_back(i->right);
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    if(nums1.size()!=nums2.size()) return false;
    if(nums1.size()==0) return true;
    for(int i=0; i<nums1.size(); i++) {
        if(nums1[i]!=nums2[i]) return false;
    }
    return solve(nv1, nv2);
}

bool anagram(TreeNode<int>*root1, int n, TreeNode<int>*root2, int m) {
    if(n!=m) return false;
    vector<TreeNode<int>*> v1, v2;
    v1.push_back(root1);
    v2.push_back(root2);
    return solve(v1, v2);
}

signed main() {
    //code here
}