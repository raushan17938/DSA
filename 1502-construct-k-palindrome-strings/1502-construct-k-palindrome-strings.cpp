class Solution {
public:
    bool canConstruct(string s, int k) {
         if (k > s.size()) return false;

        unordered_map<char, int> charCount;
       
        for (char c : s) {
            charCount[c]++;
        }

        int oddCount = 0;
       
        for (auto &entry : charCount) {
            if (entry.second % 2 != 0) {
                oddCount++;
            }
        }

       
        
      
        return oddCount <= k;
    }
};