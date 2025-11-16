class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int m = a.size(), n = b.size(), res = 0;
        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], cur + 1);
                }
                if (b[j] < a[i]) {
                    cur = max(cur, dp[j]);
                }
                res = max(res, dp[j]);
            }
        }
        return res;
    }
};