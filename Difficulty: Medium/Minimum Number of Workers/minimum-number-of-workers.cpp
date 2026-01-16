class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                intervals.push_back({max(0, i - arr[i]), min(n - 1, i + arr[i])});
            }
        }

        sort(intervals.begin(), intervals.end());

        int count = 0;
        int target = 0;
        int i = 0;
        
        while (target < n) {
            int max_reach = -1;
            
            while (i < intervals.size() && intervals[i].first <= target) {
                max_reach = max(max_reach, intervals[i].second);
                i++;
            }

            if (max_reach < target) {
                return -1;
            }

            count++;
            target = max_reach + 1;
        }

        return count;
    }
};