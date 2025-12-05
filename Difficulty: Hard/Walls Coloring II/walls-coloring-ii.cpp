class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        
        if (k == 0) return -1;
        if (k == 1) return (n == 1) ? costs[0][0] : -1;

        int min1 = INT_MAX, min2 = INT_MAX;
        int min1Index = -1;

        for (int j = 0; j < k; j++) {
            if (costs[0][j] < min1) {
                min2 = min1;
                min1 = costs[0][j];
                min1Index = j;
            } else if (costs[0][j] < min2) {
                min2 = costs[0][j];
            }
        }

        for (int i = 1; i < n; i++) {
            int curMin1 = INT_MAX, curMin2 = INT_MAX;
            int curMin1Index = -1;

            for (int j = 0; j < k; j++) {

                int cost = costs[i][j] + (j == min1Index ? min2 : min1);

                if (cost < curMin1) {
                    curMin2 = curMin1;
                    curMin1 = cost;
                    curMin1Index = j;
                } else if (cost < curMin2) {
                    curMin2 = cost;
                }
            }
            
            min1 = curMin1;
            min2 = curMin2;
            min1Index = curMin1Index;
        }

        return min1;
    }
};