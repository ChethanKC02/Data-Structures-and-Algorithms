class Solution
{
    public:
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int>>> mp;
        queue<pair<Node*,pair<int,int>>> q;
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            Node *node = q.front().first;
            int hd = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            mp[hd][level].push_back(node->data);
            if(node->left){
                q.push(make_pair(node->left,make_pair(hd-1,level+1)));
            }
            if(node->right){
                q.push(make_pair(node->right,make_pair(hd+1,level+1)));
            }
        }
        for(auto i:mp){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
