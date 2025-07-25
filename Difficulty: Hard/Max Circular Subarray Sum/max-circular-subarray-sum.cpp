class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        int maxKadane = kadane(arr);
        int totalSum = 0;
        for (int& x : arr) {
            totalSum += x;
            x = -x;
        }
        int maxCircular = totalSum + kadane(arr);
        return maxCircular == 0 ? maxKadane : max(maxKadane, maxCircular);
    }
private:
    int kadane(vector<int>& arr) {
        int maxSum = arr[0], currSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};