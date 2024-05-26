class Solution {
private:
    vector<int> v;
    
    void left(Node *root){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return;
        }
        v.push_back(root->data);
        (root->left)?left(root->left):left(root->right);
    }
    
    void leaf(Node *root){
        if(root){
            if(root->left == nullptr && root->right == nullptr){
                v.push_back(root->data);
            }
            leaf(root->left);
            leaf(root->right);
        }
    }
    
    void right(Node *root){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return;
        }
        (root->right)?right(root->right):right(root->left);
        v.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        if(root == nullptr) return v;
        v.push_back(root->data);
        left(root->left);
        leaf(root->left);
        leaf(root->right);
        right(root->right);
        return v;
    }
};