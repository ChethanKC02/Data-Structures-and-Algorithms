
class Solution{
    private:
    int height(Node *root){
        if(root == nullptr){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    public:
    bool isBalanced(Node *root)
    {
        if(root == nullptr){
            return true;
        }
        if(isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left)-height(root->right))<=1){
            return true;
        }
        else{
            return false;
        }
    }
};

// O(n*n)

// optimal


class Solution{
    private:
    pair<bool,int> solve(Node *root){
        if(root == nullptr){
            return make_pair(true,0);
        }
        pair<bool,int> l = solve(root->left);
        pair<bool,int> r = solve(root->right);
        
        return make_pair(l.first && r.first && abs(l.second - r.second) <= 1, max(l.second,r.second) +1);
        
    }
    public:
    bool isBalanced(Node *root)
    {
        return solve(root).first;
    }
};
