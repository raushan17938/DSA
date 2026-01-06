class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int current_xor = 0;
        for (int i = 0; i < k; i++) {
            current_xor ^= arr[i];
        }
        int max_xor = current_xor;
        for (int i = k; i < arr.size(); i++) {
            current_xor = current_xor ^ arr[i - k] ^ arr[i];
            max_xor = max(max_xor, current_xor);
        }
        return max_xor;
    }
};