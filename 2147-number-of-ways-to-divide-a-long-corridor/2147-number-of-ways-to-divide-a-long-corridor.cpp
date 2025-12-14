class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
      

        int dp[n][3];
        memset(dp, -1, sizeof(dp));
      
        const int MOD = 1e9 + 7;
      

        auto dfs = [&](this auto&& dfs, int currentIndex, int seatsInSection) -> int {
            if (currentIndex >= n) {
                return seatsInSection == 2 ? 1 : 0;
            }
          
            if (dp[currentIndex][seatsInSection] != -1) {
                return dp[currentIndex][seatsInSection];
            }
          
            int newSeatsCount = seatsInSection;
            if (corridor[currentIndex] == 'S') {
                newSeatsCount++;
            }
          
            if (newSeatsCount > 2) {
                return dp[currentIndex][seatsInSection] = 0;
            }
          
            dp[currentIndex][seatsInSection] = dfs(currentIndex + 1, newSeatsCount);
          

            if (newSeatsCount == 2) {
                dp[currentIndex][seatsInSection] = 
                    (dp[currentIndex][seatsInSection] + dfs(currentIndex + 1, 0)) % MOD;
            }
          
            return dp[currentIndex][seatsInSection];
        };
      
        return dfs(0, 0);
    }
};
