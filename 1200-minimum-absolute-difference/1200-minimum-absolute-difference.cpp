class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
      
        int minDifference = 1 << 30;
        int arraySize = arr.size();
      
        for (int i = 0; i < arraySize - 1; ++i) {
            int currentDifference = arr[i + 1] - arr[i];
            minDifference = min(minDifference, currentDifference);
        }
      
        vector<vector<int>> result;
      
        for (int i = 0; i < arraySize - 1; ++i) {
            if (arr[i + 1] - arr[i] == minDifference) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
      
        return result;
    }
};
