class Solution {
public:
    int longestSubarray(vector<int>& nums) {
     
        int size = nums.size();

       
        vector<int> left(size, 0);
        vector<int> right(size, 0);

       
        for (int i = 1; i < size; ++i) {
            if (nums[i - 1] == 1) {
                left[i] = left[i - 1] + 1;
            }
        }

       
        for (int i = size - 2; i >= 0; --i) {
            if (nums[i + 1] == 1) {
                right[i] = right[i + 1] + 1;
            }
        }

        
        int max_length = 0;

        
        for (int i = 0; i < size; ++i) {
            
            max_length = max(max_length, left[i] + right[i]);
        }

   
        return max_length;
    }
};
