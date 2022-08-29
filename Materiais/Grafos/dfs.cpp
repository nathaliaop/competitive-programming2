vector<vector<int>> graph;
vector<bool> visited;    

void dfs(int vertex){
    visited[vertex] = true;

    for(int w: graph[vertex]){
        if(!visited[w]){
            dfs(w);
        }
    }    
}