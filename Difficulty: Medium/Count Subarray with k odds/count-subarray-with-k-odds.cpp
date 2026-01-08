class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> counts(n + 1, 0);
        counts[0] = 1;
        int odd = 0, ans = 0;
        for (int x : arr) {
            if (x & 1) odd++;
            if (odd >= k) ans += counts[odd - k];
            counts[odd]++;
        }
        return ans;
    }
};