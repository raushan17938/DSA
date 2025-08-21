class Solution {
public:
    int maxMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int l = 0, r = a.back() - a[0], ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 1, last = a[0];
            for (int i = 1; i < a.size() && cnt < k; i++)
                if (a[i] - last >= m) cnt++, last = a[i];
            cnt >= k ? ans = m, l = m + 1 : r = m - 1;
        }
        return ans;
    }
};