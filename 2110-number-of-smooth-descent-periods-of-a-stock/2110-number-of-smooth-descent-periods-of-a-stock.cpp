class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long totalPeriods = 0;
        int n = prices.size();
      
        for (int startIdx = 0, endIdx = 0; startIdx < n; startIdx = endIdx) {
            endIdx = startIdx + 1;
          
            while (endIdx < n && prices[endIdx - 1] - prices[endIdx] == 1) {
                ++endIdx;
            }
          
            int sequenceLength = endIdx - startIdx;
          
           
            totalPeriods += (1LL + sequenceLength) * sequenceLength / 2;
        }
      
        return totalPeriods;
    }
};