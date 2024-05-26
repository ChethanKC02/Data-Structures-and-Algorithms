
class Solution
{
private:
    void solve(Node *root, vector<int> &v, int l){
        if(root){
            if(v.size() == l){
                v.push_back(root->data);
            }
            solve(root->right,v,l+1);
            solve(root->left,v,l+1);
        }
    }
public:
    vector<int> rightView(Node *root)
    {
        vector<int> v;
        solve(root,v,0);
        return v;
    }
};
