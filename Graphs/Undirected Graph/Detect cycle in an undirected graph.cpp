#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int> adj[], int start, int parent, bool vis[]){
        
        vis[start] = true;
        
        for(auto node: adj[start]){
            if(!vis[node]){
                if(dfs(adj, node, start, vis))
                    return true;
            }
            else if(node != parent){
                return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[]){
	    bool vis[V] = {0};
	    for(int i = 0; i<V; i++){
	        if(!vis[i] and dfs(adj, i, -1, vis)){
	            return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
