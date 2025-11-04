class Solution {
  public:
    int minCost(std::vector<int>& height) {
        int n = height.size();
        if (n <= 1) {
            return 0;
        }

        int prev2 = 0;
        int prev1 = std::abs(height[1] - height[0]);

        for (int i = 2; i < n; ++i) {
            int cost_from_prev1 = prev1 + std::abs(height[i] - height[i-1]);
            int cost_from_prev2 = prev2 + std::abs(height[i] - height[i-2]);

            int current_cost = std::min(cost_from_prev1, cost_from_prev2);
            
            prev2 = prev1;
            prev1 = current_cost;
        }

        return prev1;
    }
};