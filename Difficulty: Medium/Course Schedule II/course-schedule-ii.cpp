class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]), d[p[0]]++;
        queue<int> q;
        vector<int> r;
        for(int i = 0; i < n; i++) if(!d[i]) q.push(i);
        while(q.size()) {
            int u = q.front(); q.pop(); r.push_back(u);
            for(int v : g[u]) if(!--d[v]) q.push(v);
        }
        return r.size() == n ? r : vector<int>{};
    }
};