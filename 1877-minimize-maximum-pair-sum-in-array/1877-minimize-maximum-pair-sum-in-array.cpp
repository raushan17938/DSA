class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
      
        int max_pair_sum = 0;
        int n = nums.size();
      
     
        for (int i = 0; i < n / 2; ++i) {
            int current_pair_sum = nums[i] + nums[n - i - 1];
          
            max_pair_sum = max(max_pair_sum, current_pair_sum);
        }
      
        return max_pair_sum;
    }
};
