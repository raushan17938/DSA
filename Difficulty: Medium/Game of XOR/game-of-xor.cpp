class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int xor_sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (((i + 1) * (n - i)) & 1) xor_sum ^= arr[i];
        }
        return xor_sum;
    }
};