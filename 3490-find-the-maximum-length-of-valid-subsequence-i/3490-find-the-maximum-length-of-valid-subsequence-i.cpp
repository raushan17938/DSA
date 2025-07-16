class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        const int k = 2; 
        int dp[k][k];    
        memset(dp, 0, sizeof(dp)); 
        int maxLength = 0; 

        
        for (int num : nums) {
            int remainder = num % k; 

            for (int j = 0; j < k; ++j) {
                int requiredRemainder = (j - remainder + k) % k; 

               
                dp[remainder][requiredRemainder] = dp[requiredRemainder][remainder] + 1;

                maxLength = std::max(maxLength, dp[remainder][requiredRemainder]);
            }
        }
        return maxLength; 
    }
};