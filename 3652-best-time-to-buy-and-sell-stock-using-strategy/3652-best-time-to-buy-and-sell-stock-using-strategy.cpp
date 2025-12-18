class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long baseProfit = 0;
        
        for (int i = 0; i < n; i++) {
            baseProfit += (long long)prices[i] * strategy[i];
        }
        
        long long maxP = baseProfit;
        long long currentOriginalSum = 0;
        long long currentModifiedSum = 0;
        
        for (int i = 0; i < k; i++) {
            currentOriginalSum += (long long)prices[i] * strategy[i];
            if (i >= k / 2) {
                currentModifiedSum += prices[i];
            }
        }
        
        maxP = max(maxP, baseProfit - currentOriginalSum + currentModifiedSum);
        
        for (int i = k; i < n; i++) {
            currentOriginalSum -= (long long)prices[i - k] * strategy[i - k];
            currentOriginalSum += (long long)prices[i] * strategy[i];
            
            currentModifiedSum -= prices[i - k + k / 2];
            currentModifiedSum += prices[i];
            
            maxP = max(maxP, baseProfit - currentOriginalSum + currentModifiedSum);
        }
        
        return maxP;
    }
};