//https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    vector<int> v;
    void inorder(TreeNode* root){
        if(root){
            v.push_back(root->val);
            inorder(root->left);
            inorder(root->right);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int ans = INT_MAX;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++) ans = min(ans, v[i+1]-v[i]);
        return ans;
    }
};