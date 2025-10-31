class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int min_cycle = INT_MAX;

        for (int i = 0; i < V; ++i) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;

            q.push(i);
            dist[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (v != parent[u]) {
                        min_cycle = min(min_cycle, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        if (min_cycle == INT_MAX) {
            return -1;
        } else {
            return min_cycle;
        }
    }
};