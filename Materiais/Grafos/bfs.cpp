void bfs(int start){
    
    queue<int> q;
    q.push(start);

    vector<bool> visited(GRAPH_MAX_SIZE,false);
    visited[start] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int w: graph[u]){
            if(not visited[w]){
                q.push(w);
                visited[w] = true;
            }
        }
    }

}