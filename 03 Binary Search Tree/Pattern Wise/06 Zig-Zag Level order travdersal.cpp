
class Solution{
public:
    vector<int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        queue<Node *> q;
        q.push(root);
        bool RtoL = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size,-1);
            for(int i=0;i<size;i++){
                Node *n = q.front();
                q.pop();
                if(RtoL){
                    v[i] = n->data;
                }
                else{
                    v[size-i-1] = n->data;
                }
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            RtoL = !RtoL;t
            for(int i:v){
                ans.push_back(i);
            }
        }
        return ans;
    }
};