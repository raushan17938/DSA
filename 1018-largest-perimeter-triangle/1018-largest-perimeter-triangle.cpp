class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
      
        for (int i = nums.size() - 1; i >= 2; --i) {
          
            int sumOfTwoSmallerSides = nums[i - 1] + nums[i - 2];
          
            if (sumOfTwoSmallerSides > nums[i]) {
                return sumOfTwoSmallerSides + nums[i];
            }
        }
      
        return 0;
    }
};