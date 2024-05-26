class Solution
{
private:
    int maxL = 0, maxS = 0;
    void solve(Node *root, int level, int sum){
        if(root){
            if(level>maxL){
                maxS = sum + root->data;
                maxL = level;
            }
            if(level == maxL){
                maxS = max(maxS,sum+root->data);
            }
            solve(root->left,level+1,sum+root->data);
            solve(root->right,level+1,sum+root->data);
        }
    }
public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        solve(root,0,0);
        return maxS;
    }
};