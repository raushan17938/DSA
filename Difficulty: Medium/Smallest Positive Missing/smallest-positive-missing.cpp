class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) arr[i] = n + 1;
        }
        for (int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;
            if (idx < n && arr[idx] > 0) arr[idx] = -arr[idx];
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) return i + 1;
        }
        return n + 1;
    }
};