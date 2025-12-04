class Solution {
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += freq[k];
                }

                for (int r = i; r <= j; r++) {
                    int c = ((r > i) ? dp[i][r-1] : 0) + 
                            ((r < j) ? dp[r+1][j] : 0) + 
                            sum;
                    
                    if (c < dp[i][j]) {
                        dp[i][j] = c;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};