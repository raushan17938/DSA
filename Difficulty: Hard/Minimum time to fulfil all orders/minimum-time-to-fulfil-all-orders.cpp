class Solution {
  public:
    int minTime(vector<int>& ranks, int n) {
        int left = 0;
        int right = 1e8;
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int donuts = 0;

            for (int r : ranks) {
                int k = (sqrt(1 + 8.0 * mid / r) - 1) / 2;
                donuts += k;
                if (donuts >= n) break;
            }

            if (donuts >= n) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};