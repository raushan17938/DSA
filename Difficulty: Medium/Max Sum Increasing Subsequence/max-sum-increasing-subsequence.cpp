class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + arr[i]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};