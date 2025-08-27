class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        unordered_map<int, int> nextDigit = {{1, 2}, {2, 0}, {0, 2}};
        
        // Memoization: dp[i][j][dir][turned] stores max length starting at (i,j)
        vector<vector<vector<vector<int>>>> dp(
            m, vector<vector<vector<int>>>(
                n, vector<vector<int>>(4, vector<int>(2, -1))
            )
        );

        vector<pair<int,int>> directions = {{1,1}, {-1,1}, {1,-1}, {-1,-1}};

        function<int(int,int,int,bool)> dfs = [&](int i, int j, int dir, bool turned) -> int {
            if (dp[i][j][dir][turned] != -1) return dp[i][j][dir][turned];
            
            int di = directions[dir].first;
            int dj = directions[dir].second;
            int successor = nextDigit[grid[i][j]];
            int res = 1;
            
            // Move straight
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == successor) {
                res = max(res, 1 + dfs(ni, nj, dir, turned));
            }

            // Turn once
            if (!turned) {
                int new_di = dj, new_dj = -di; // 90-degree turn
                int new_dir = -1;
                for (int k=0; k<4; k++) {
                    if (directions[k].first == new_di && directions[k].second == new_dj) {
                        new_dir = k; break;
                    }
                }
                int ni2 = i + new_di, nj2 = j + new_dj;
                if (ni2 >= 0 && ni2 < m && nj2 >= 0 && nj2 < n && grid[ni2][nj2] == successor) {
                    res = max(res, 1 + dfs(ni2, nj2, new_dir, true));
                }
            }

            return dp[i][j][dir][turned] = res;
        };

        int ans = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] != 1) continue;
                for (int d=0; d<4; d++) {
                    ans = max(ans, dfs(i,j,d,false));
                }
            }
        }
        return ans;
    }
};
