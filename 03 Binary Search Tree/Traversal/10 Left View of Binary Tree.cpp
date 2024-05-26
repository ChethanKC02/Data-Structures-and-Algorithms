class Solution{
private:
    void solve(Node *root, vector<int> &v, int level){
        if(root){
            if(level == v.size()){
                v.push_back(root->data);
            }
            solve(root->left,v,level+1);
            solve(root->right,v,level+1);
        }
    }
public:
    vector<int> leftView(Node *root)
    {
        vector<int> v;
        solve(root,v,0);
        return v;
    }
};