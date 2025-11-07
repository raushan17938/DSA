class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end());
        int n = jobs.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int l = i + 1, r = n - 1, nxt = n;
            while (l <= r) {
                int m = (l + r) / 2;
                if (jobs[m][0] >= jobs[i][1]) {
                    nxt = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            dp[i] = max(jobs[i][2] + dp[nxt], dp[i + 1]);
        }
        return dp[0];
    }
};