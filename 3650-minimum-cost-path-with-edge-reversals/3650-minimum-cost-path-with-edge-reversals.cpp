class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,2*w});
        }
        const long long INF = LLONG_MAX/2;
        vector<long long> dist(n, INF);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto &p : graph[u]){
                int v = p.first;
                long long w = p.second;
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[n-1] == INF ? -1 : dist[n-1];
    }
};