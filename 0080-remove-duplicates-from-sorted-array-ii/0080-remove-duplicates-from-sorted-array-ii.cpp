class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // If array has 2 or fewer elements, no need to remove anything
        if (n <= 2) return n;

        // Start from the 3rd element (index 2)
        // because the first two elements are always kept
        int index = 2;

        for (int i = 2; i < n; i++) {
            // Check if current number is different from the number 
            // TWO positions back in our "new" valid array
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i]; // Overwrite
                index++;
            }
        }
        return index;
    }
};