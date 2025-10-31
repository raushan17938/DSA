class Solution {
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == 'O') g[i][j] = '-';
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != '-') return;
            g[i][j] = 'O';
            dfs(i + 1, j); dfs(i - 1, j); dfs(i, j + 1); dfs(i, j - 1);
        };
        for (int i = 0; i < m; i++) { dfs(i, 0); dfs(i, n - 1); }
        for (int j = 0; j < n; j++) { dfs(0, j); dfs(m - 1, j); }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
};