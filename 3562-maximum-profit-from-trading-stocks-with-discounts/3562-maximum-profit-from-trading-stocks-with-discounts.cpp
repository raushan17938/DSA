class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> adj(n);
        for (const auto& edge : hierarchy) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
        }

   
        auto dfs = [&](auto&& self, int u) -> pair<vector<int>, vector<int>> {
           
            vector<int> dp_skip(budget + 1, -1e9);
            vector<int> dp_buy(budget + 1, -1e9);
            
            dp_skip[0] = 0;
            dp_buy[0] = 0;

            for (int v : adj[u]) {
                pair<vector<int>, vector<int>> child_res = self(self, v);
                const vector<int>& child_not_bought = child_res.first;
                const vector<int>& child_bought = child_res.second;

                vector<int> next_dp_skip(budget + 1, -1e9);
                for (int b = budget; b >= 0; --b) {
                    for (int k = 0; k <= b; ++k) {
                        if (dp_skip[b - k] > -1e8 && child_not_bought[k] > -1e8) {
                            next_dp_skip[b] = max(next_dp_skip[b], dp_skip[b - k] + child_not_bought[k]);
                        }
                    }
                }
                dp_skip = next_dp_skip;

                vector<int> next_dp_buy(budget + 1, -1e9);
                for (int b = budget; b >= 0; --b) {
                    for (int k = 0; k <= b; ++k) {
                        if (dp_buy[b - k] > -1e8 && child_bought[k] > -1e8) {
                            next_dp_buy[b] = max(next_dp_buy[b], dp_buy[b - k] + child_bought[k]);
                        }
                    }
                }
                dp_buy = next_dp_buy;
            }

            pair<vector<int>, vector<int>> res;
            res.first.assign(budget + 1, -1e9);
            res.second.assign(budget + 1, -1e9);

           
            for (int b = 0; b <= budget; ++b) res.first[b] = dp_skip[b];
            
            
            int cost_full = present[u];
            int profit_full = future[u] - cost_full;
            for (int b = cost_full; b <= budget; ++b) {
                if (dp_buy[b - cost_full] > -1e8) {
                    res.first[b] = max(res.first[b], dp_buy[b - cost_full] + profit_full);
                }
            }

          
            for (int b = 0; b <= budget; ++b) res.second[b] = dp_skip[b];

           
            int cost_half = present[u] / 2;
            int profit_half = future[u] - cost_half;
            for (int b = cost_half; b <= budget; ++b) {
                if (dp_buy[b - cost_half] > -1e8) {
                    res.second[b] = max(res.second[b], dp_buy[b - cost_half] + profit_half);
                }
            }

            return res;
        };

    
        auto root_res = dfs(dfs, 0);
        
        int ans = 0;
        for (int x : root_res.first) {
            ans = max(ans, x);
        }
        return ans;
    }
};