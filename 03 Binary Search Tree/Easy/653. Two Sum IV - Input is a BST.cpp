//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    unordered_map<int,bool> mp;
    bool  ans = false;
    int target;
    void solve(TreeNode *root){
        if(!ans && root){
            if(mp[target - root->val]){
                ans = true;
            }
            mp[root->val] = true;
            solve(root->left);
            solve(root->right);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        target = k;
        solve(root);
        return ans;
    }
};