void dfs(vector<int> adj[], stack<int> &s, int src, bool vis[]){
        vis[src] = true;
        for(auto node: adj[src]){
            if(!vis[node]){
                dfs(adj, s, node, vis);
            }
        }
        s.push(src);
    }
    
    void revDfs(vector<int> g[], int src, bool vis[]){
        vis[src] = true;
        for(auto node: g[src]){
            if(!vis[node]){
                revDfs(g, node, vis);
            }
        }
    }
    
    int kosaraju(int V, vector<int> adj[]) {
        stack<int> s;
        bool vis[V] = {0};
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(adj, s, i, vis);
            }
        }
        
        vector<int> g[V];
        for(int i = 0; i<V; i++){
            for(auto e: adj[i]){
                g[e].push_back(i);
            }
        }
        memset(vis,false, sizeof(vis));
        int count = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!vis[node]){
                count++;
                revDfs(g, node, vis);
            }
        }
        return count;
    }
