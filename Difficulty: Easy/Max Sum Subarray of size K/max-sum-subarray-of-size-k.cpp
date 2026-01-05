class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        long long currentSum = 0;
        for (int i = 0; i < k; ++i) {
            currentSum += arr[i];
        }
        long long maxSum = currentSum;
        for (int i = k; i < arr.size(); ++i) {
            currentSum += arr[i] - arr[i - k];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
        return maxSum;
    }
};