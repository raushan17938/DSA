class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> result(n, -1);  
      
        set<int> sunnyDays;
      
        unordered_map<int, int> lastRainedLakes;
      
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
          
            if (lake > 0) {  
                if (lastRainedLakes.count(lake)) {
                    auto sunnyDayIt = sunnyDays.upper_bound(lastRainedLakes[lake]);
                  
                    if (sunnyDayIt == sunnyDays.end()) {
                        return {};  
                    }
                  
                    result[*sunnyDayIt] = lake;
                    sunnyDays.erase(sunnyDayIt);  
                }
              
               
                lastRainedLakes[lake] = i;
            } else {  
                sunnyDays.insert(i);  
                result[i] = 1;  
            }
        }
      
        return result;
    }
};
