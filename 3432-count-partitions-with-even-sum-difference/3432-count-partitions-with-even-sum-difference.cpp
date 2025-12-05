class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
      
        int partitionCount = 0;
      
        for (int i = 0; i < nums.size() - 1; ++i) {
            leftSum += nums[i];
            rightSum -= nums[i];
          
          
            if ((leftSum - rightSum) % 2 == 0) {
                ++partitionCount;
            }
        }
      
        return partitionCount;
    }
};