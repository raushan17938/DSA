class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        int rightEven = 0, rightOdd = 0;
        int leftEven = 0, leftOdd = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) rightEven += arr[i];
            else rightOdd += arr[i];
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) rightEven -= arr[i];
            else rightOdd -= arr[i];

            if (leftEven + rightOdd == leftOdd + rightEven) {
                count++;
            }

            if (i % 2 == 0) leftEven += arr[i];
            else leftOdd += arr[i];
        }

        return count;
    }
};