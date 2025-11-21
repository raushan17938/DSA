class Solution {
public:
    // Function to find the smallest and second smallest elements
    vector<int> minAnd2ndMin(vector<int>& arr) {
        int n = arr.size();
        
        // If array has less than 2 elements, second smallest cannot exist
        if (n < 2) return {-1};

        int smallest = INT_MAX;
        int second_smallest = INT_MAX;

        for (int num : arr) {
            if (num < smallest) {
                // Found a new smallest, so the old smallest becomes the second smallest
                second_smallest = smallest;
                smallest = num;
            } 
            else if (num < second_smallest && num != smallest) {
                // Found a number between smallest and second_smallest
                second_smallest = num;
            }
        }

        // If second_smallest was never updated, it means all elements were equal
        if (second_smallest == INT_MAX) {
            return {-1};
        }

        return {smallest, second_smallest};
    }
};