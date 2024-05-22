// Given an undirected and disconnected graph G(V, E), 
// containing 'V' vertices and 'E' edges, the information about edges is given 
// using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

// E is the number of edges present in graph G.0


void dfs(int node, vector<bool> &vis, vector<vector<int>> &list, vector<int> &path){
    vis[node] = true;
    path.push_back(node);
    for(int i:list[node]){
        if(vis[i] == false){
            dfs(i,vis,list,path);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans,list(V);
    vector<bool>visited(V,false);
    for (vector<int> i : edges) {
        list[i[0]].push_back(i[1]);        
        list[i[1]].push_back(i[0]);
    }

    for(int i=0;i<V;i++){
        if(visited[i] == false){
            vector<int> k;
            dfs(i,visited,list,k);
            ans.push_back(k);
        }
    }

    return ans; 
}