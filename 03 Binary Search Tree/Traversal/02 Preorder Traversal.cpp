class Solution{
private:
    void Preorder(Node *root, vector<int> &v){
        if(root){
            Preorder(root->left, v);
            v.push_back(root->data);
            Preorder(root->right, v);
        }
    }
public:
    vector<int> PreorderTraversal(Node *root){
        vector<int> v;
        Preorder(root, v);
        return v;
    }
};