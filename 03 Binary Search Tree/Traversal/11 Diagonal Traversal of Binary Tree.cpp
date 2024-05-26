
void solve(Node *root, int hd,map<int,vector<int>> &mp){
    if(root){
        mp[hd].push_back(root->data);
        solve(root->left,hd-1,mp);
        solve(root->right,hd,mp);
    }
}

vector<int> diagonal(Node *root)
{
    map<int,vector<int>> mp;
    vector<int> ans;
    solve(root,0,mp);for(auto i=mp.rbegin();i!=mp.rend();++i){
        ans.insert(ans.end(),i->second.begin(),i->second.end());
    }
    return ans;
}