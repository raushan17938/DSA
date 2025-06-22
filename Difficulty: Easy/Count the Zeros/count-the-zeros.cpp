// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int firstZeroIndex = -1;

        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == 0) {
                firstZeroIndex = mid;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }


        if (firstZeroIndex == -1)
            return 0;

    
        return n - firstZeroIndex;
    }
};
