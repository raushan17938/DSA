class Solution {
public:
    int getMinDiff(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = a[n-1] - a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] >= k) {
                int mn = min(a[0] + k, a[i] - k);
                int mx = max(a[n-1] - k, a[i-1] + k);
                ans = min(ans, mx - mn);
            }
        }
        return ans;
    }
};