class Solution{
private:
    void Postorder(Node *root, vector<int> &v){
        if(root){
            Postorder(root->left, v);
            v.push_back(root->data);
            Postorder(root->right, v);
        }
    }
public:
    vector<int> PostorderTraversal(Node *root){
        vector<int> v;
        Postorder(root, v);
        return v;
    }
};