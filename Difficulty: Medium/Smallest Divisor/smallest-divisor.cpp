class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end()), n = arr.size();
        while (l < h) {
            int m = (l + h) >> 1, s = 0;
            for (int i = 0; i < n; ++i) s += (arr[i] + m - 1) / m;
            s <= k ? h = m : l = m + 1;
        }
        return l;
    }
};
