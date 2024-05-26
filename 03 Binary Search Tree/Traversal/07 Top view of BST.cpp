class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            Node *node = q.front().first;
            int HD = q.front().second;
            q.pop();
            if(mp.find(HD) == mp.end()){
                mp[HD] = node->data;
            }
            if(node->left){
                q.push(make_pair(node->left,HD-1));
            }
            if(node->right){
                q.push(make_pair(node->right,HD+1));
            }
        }
        for(pair<int,int> i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
