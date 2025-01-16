class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorNums1 = 0, xorNums2 = 0;

        
        for (int num : nums1) {
            xorNums1 ^= num;
        }
        for (int num : nums2) {
            xorNums2 ^= num;
        }

       
        bool nums1Odd = nums1.size() % 2 != 0;
        bool nums2Odd = nums2.size() % 2 != 0;

     
        int result = 0;
        if (nums1Odd) result ^= xorNums2; 
        if (nums2Odd) result ^= xorNums1; 

        return result;
    }
};