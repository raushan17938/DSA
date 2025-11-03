class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<int> out(V), safe(V);
        vector<vector<int>> g(V);
        for (auto& e : edges) out[e[0]]++, g[e[1]].push_back(e[0]);
        queue<int> q;
        for (int i = 0; i < V; i++) if (!out[i]) q.push(i), safe[i] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) if (!safe[v] && --out[v] == 0) q.push(v), safe[v] = 1;
        }
        vector<int> res;
        for (int i = 0; i < V; i++) if (safe[i]) res.push_back(i);
        return res;
    }
};