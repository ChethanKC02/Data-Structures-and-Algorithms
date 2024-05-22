// Given an adjacency list representation of a directed graph with ‘n’ vertices 
// and ‘m’ edges. Your task is to return a list consisting of Breadth-First Traversal (BFS) starting from vertex 0.

// In this traversal, one can move from vertex 'u' to vertex 'v' only if 
// there is an edge from 'u' to 'v'. The BFS traversal should include all nodes directly or indirectly connected to vertex 0.

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> v,visited(n,0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        v.push_back(node);
        for(int i:adj[node] ){
          if (!visited[i] ) {
            q.push(i);
            visited[i] = 1;
          }
        }
    }
    return v;
}