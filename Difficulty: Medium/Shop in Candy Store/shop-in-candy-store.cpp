class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), min = 0, max = 0;
        for (int i = 0, rem = n; i < rem; i++, rem -= k) min += prices[i];
        for (int j = n - 1, idx = -1; j > idx; j--, idx += k) max += prices[j];
        return {min, max};
    }
};