//https://leetcode.com/problems/find-mode-in-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int m = 0;
    unordered_map<int,int> mp;
    void solve(TreeNode *root){
        if(root){
            m = max(m,++mp[root->val]);
            solve(root->left);
            solve(root->right);
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        solve(root);
        for(const auto &[i,fr]:mp){
            if(fr == m){
                v.push_back(i);
            }
        }
        return v;
    }
};