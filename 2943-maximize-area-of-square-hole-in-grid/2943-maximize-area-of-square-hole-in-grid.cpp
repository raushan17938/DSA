class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
     
        auto findMaxConsecutiveGap = [](vector<int>& bars) {
            int maxGap = 1;       
            int currentGap = 1;    
          
            sort(bars.begin(), bars.end());
          
            for (int i = 1; i < bars.size(); ++i) {
                if (bars[i] == bars[i - 1] + 1) {
                    currentGap++;
                    maxGap = max(maxGap, currentGap);
                } else {
                    currentGap = 1;
                }
            }
          
            return maxGap + 1;
        };
      
        int maxHorizontalGap = findMaxConsecutiveGap(hBars);
        int maxVerticalGap = findMaxConsecutiveGap(vBars);
      
        int maxSquareSide = min(maxHorizontalGap, maxVerticalGap);
      
        return maxSquareSide * maxSquareSide;
    }
};