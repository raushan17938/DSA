class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        if (n == 0) return {};
        int m = mat[0].size();
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i + 1][j + 1] = (long long)mat[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
            }
        }
        
        vector<int> result;
        
        for (auto &q : queries) {
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];
            
            long long submatrixSum = dp[r2 + 1][c2 + 1] - dp[r1][c2 + 1] - dp[r2 + 1][c1] + dp[r1][c1];
                                   
            result.push_back((int)submatrixSum);
        }
        
        return result;
    }
};