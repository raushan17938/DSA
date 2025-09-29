class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), res = INT_MIN;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
        deque<int> dq;
        for (int i = a; i <= n; i++) {
            int left = i - b, right = i - a;
            while (!dq.empty() && dq.front() < left) dq.pop_front();
            while (!dq.empty() && pre[dq.back()] >= pre[right]) dq.pop_back();
            dq.push_back(right);
            res = max(res, pre[i] - pre[dq.front()]);
        }
        return res;
    }
};