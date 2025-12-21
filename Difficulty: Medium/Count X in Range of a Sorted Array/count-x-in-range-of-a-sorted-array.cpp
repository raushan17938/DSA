class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        result.reserve(queries.size()); 
        
        const int* base = arr.data();

        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int x = query[2];
            

            if (x < base[l] || x > base[r]) {
                result.push_back(0);
                continue;
            }


            auto range = equal_range(base + l, base + r + 1, x);
            
            result.push_back(range.second - range.first);
        }
        return result;
    }
};