class Solution
{
private:
    pair<int,bool> solve(Node *root){
        if(root == nullptr){
            return make_pair(0,true);
        }
        if(root->left == nullptr && root->right == nullptr){
            return make_pair(root->data,true);
        }
        pair<int,bool> l = solve(root->left);
        pair<int,bool> r = solve(root->right);
        return make_pair( l.first+r.first+root->data ,l.second && r.second && l.first + r.first == root->data );
        
    }
public:
    bool isSumTree(Node* root)
    {
        return solve(root).second;
    }
};