class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        if (arr.empty()) return 0;
        int n = arr.size();
        int bits = 0;
        for (int x : arr) {
            bits |= x;
        }
        return bits * (1 << (n - 1));
    }
};