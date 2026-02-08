class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        long long maxVal = arr[0];
        long long minVal = arr[0];
        long long result = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) {
                swap(maxVal, minVal);
            }
            maxVal = max((long long)arr[i], maxVal * arr[i]);
            minVal = min((long long)arr[i], minVal * arr[i]);
            result = max(result, maxVal);
        }
        return (int)result;
    }
};