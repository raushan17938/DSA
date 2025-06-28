class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        unordered_set<int> prefixSums;
        int sum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum == 0 || prefixSums.count(sum) > 0 || arr[i] == 0)
                return true;
            prefixSums.insert(sum);
        }

        return false;
    }
};
