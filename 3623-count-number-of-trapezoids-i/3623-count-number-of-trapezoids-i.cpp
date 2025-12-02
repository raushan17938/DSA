class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> y_counts;
        for (const auto& p : points) {
            y_counts[p[1]]++;
        }
        
        long long ans = 0;
        long long running_segments_sum = 0;
        const int MOD = 1e9 + 7;
        
        for (auto const& [y, count] : y_counts) {
            if (count < 2) continue;
            
            long long current_segments = ((long long)count * (count - 1)) / 2;
            
            current_segments %= MOD;
            
            ans = (ans + (current_segments * running_segments_sum) % MOD) % MOD;
            
            running_segments_sum = (running_segments_sum + current_segments) % MOD;
        }
        
        return (int)ans;
    }
};