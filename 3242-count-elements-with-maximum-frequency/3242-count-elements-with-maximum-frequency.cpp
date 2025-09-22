class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::unordered_map<int, int> freqMap;
        
        int maxFreq = 0;    
        int totalCount = 0; 

        for (int num : nums) {
            freqMap[num]++;
            int currentFreq = freqMap[num];

            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
                totalCount = currentFreq; 
            } 
            else if (currentFreq == maxFreq) {
                totalCount += currentFreq;
            }
        }
        
        return totalCount;
    }
};