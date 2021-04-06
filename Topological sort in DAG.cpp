void dfs(int u, stack<int> &s, vector<int> &vis, vector<int> adj[]) {
	vis[u] = 1;
	for (auto v : adj[u]) {
		if (!vis[v]) {
			dfs(v, s, vis, adj);
		}
	}

	s.push(u);
}

vector<int> topoSort(int V, vector<int> adj[]) {
	stack<int> s;
	vector<int> vis(V + 1, 0);

	for (int i = 0; i < V; i++) {
		if (!vis[i])
			dfs(i, s, vis, adj);
	}

	vector<int> res;
	while (!s.empty()) {
		res.push_back(s.top());
		s.pop();
	}

	return res;
}
