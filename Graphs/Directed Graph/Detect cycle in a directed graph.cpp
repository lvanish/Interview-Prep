#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    bool dfs(int node, vector<int> adj[], bool vis[], bool rec[]){
        if(!vis[node]){
            vis[node] = true;
            rec[node] = true;
            for(auto x: adj[node]){
                if(!vis[x] and dfs(x, adj, vis, rec)) return true;
                else if(rec[x] == true) return true;
            }
        }
        rec[node] = false;
        return false;
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
	    bool vis[V] = {0}, rec[V] = {0};
	   	for(int i = 0; i<V; i++){
	   	    if(!vis[i] and dfs(i, adj, vis, rec))
	   	        return true;
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
