class Solution {
public:
    int maxFreqSum(string s) {
        int frequency[26]{};
      
        for (char c : s) {
            ++frequency[c - 'a'];
        }
      
       
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;
      
        // Iterate through all 26 letters to find max frequencies
        for (int i = 0; i < 26; ++i) {
            char currentChar = 'a' + i;
          
            if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || 
                currentChar == 'o' || currentChar == 'u') {
                maxVowelFreq = max(maxVowelFreq, frequency[i]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, frequency[i]);
            }
        }
      
     
        return maxVowelFreq + maxConsonantFreq;
    }
};