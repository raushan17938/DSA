class Solution {
public:
    bool canSplit(vector<int>& arr, int k, int maxSum) {
        int subarrays = 1, currentSum = 0;
        for (int num : arr) {
            if (num > maxSum) return false;
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } else {
                subarrays++;
                currentSum = num;
                if (subarrays > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& arr, int k) {
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(arr, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
