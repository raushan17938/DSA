class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // Check if current element is greater than the next one
            // Use modulo operator % to handle the wrap-around case (last element vs first)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        // A sorted and rotated array can have at most 1 "drop" where a larger number is followed by a smaller one
        return count <= 1;
    }
};