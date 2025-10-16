class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        int remainderCount[value];
        memset(remainderCount, 0, sizeof(remainderCount));
      
        
        for (int num : nums) {
            int remainder = ((num % value) + value) % value;
            ++remainderCount[remainder];
        }
      
      
        for (int i = 0; ; ++i) {
            int remainderClass = i % value;
          
            if (remainderCount[remainderClass] == 0) {
                return i;
            }
          
            --remainderCount[remainderClass];
        }
    }
};