class Solution{
private:
    void inorder(Node *root, vector<int> &v){
        if(root){
            inorder(root->left, v);
            v.push_back(root->data);
            inorder(root->right, v);
        }
    }
public:
    vector<int> inorderTraversal(Node *root){
        vector<int> v;
        inorder(root, v);
        return v;
    }
};