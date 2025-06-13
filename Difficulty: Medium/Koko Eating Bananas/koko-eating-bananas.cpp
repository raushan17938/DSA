class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int lo = 1, hi = arr.back();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;
            bool valid = true;

            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
                if (hours > k) {
                    valid = false;
                    break; 
                }
            }

            if (valid)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};