class Solution {
public:
    int minCostPath(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();
            if (x == n - 1 && y == m - 1) return d;
            if (d > dist[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nd = max(d, abs(mat[nx][ny] - mat[x][y]));
                    if (nd < dist[nx][ny]) {
                        dist[nx][ny] = nd;
                        pq.push({nd, nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};