class Solution {
public:
   
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int numSize = nums.size();

        vector<pair<int, int>> indexedNums;

      
        for (int i = 0; i < numSize; ++i) {
            indexedNums.push_back({i, nums[i]});
        }

       
        sort(indexedNums.begin(), indexedNums.end(), [](const auto& x1, const auto& x2) {
            return x1.second > x2.second;
        });

        sort(indexedNums.begin(), indexedNums.begin() + k,
             [](const auto& x1, const auto& x2) {
                 return x1.first < x2.first;
             });

   
        vector<int> ans;
        ans.reserve(k); 

    
        for (int i = 0; i < k; ++i) {
            ans.push_back(indexedNums[i].second);
        }

        return ans;
    }
};