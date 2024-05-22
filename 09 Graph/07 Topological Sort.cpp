// A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

// Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

// Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

// For example, Consider the DAG shown in the picture.

#include <bits/stdc++.h> 
void dfs(int node, vector<vector<int>> &ed, vector<bool> &v, stack<int> &st){
    v[node] = true;
    for(int adj:ed[node]){
        if(v[adj] == false){
            dfs(adj,ed,v,st);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    stack<int> st;
    vector<bool> vis(v,false);
    vector<vector<int>> list(v);
    for(vector<int> i:edges){
        list[i[0]].push_back(i[1]);
    }

    vector<int> ans;
    for(int i=0;i<v;i++){
        if(vis[i] == false){
            dfs(i,list,vis,st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}