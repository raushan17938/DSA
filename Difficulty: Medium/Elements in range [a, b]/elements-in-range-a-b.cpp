class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        sort(arr.begin(), arr.end());
        
        vector<int> result;
        
        for(const auto& query : queries) {
            int L = query[0];
            int R = query[1];
            
            auto it_start = lower_bound(arr.begin(), arr.end(), L);
            auto it_end = upper_bound(arr.begin(), arr.end(), R);
            
            int count = it_end - it_start;
            
            if (count < 0) count = 0;
            
            result.push_back(count);
        }
        
        return result;
    }
};