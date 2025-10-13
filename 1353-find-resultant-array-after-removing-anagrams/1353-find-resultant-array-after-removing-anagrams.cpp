class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       
        auto areNotAnagrams = [](const string& str1, const string& str2) -> bool {
            if (str1.size() != str2.size()) {
                return true;
            }
          
            int charFrequency[26] = {0};
            for (const char& ch : str1) {
                charFrequency[ch - 'a']++;
            }
          
         
            for (const char& ch : str2) {
                charFrequency[ch - 'a']--;
                if (charFrequency[ch - 'a'] < 0) {
                    return true;
                }
            }
          
            return false;
        };
      
       
        vector<string> result;
        result.push_back(words[0]);
      
    
        for (int i = 1; i < words.size(); i++) {
            if (areNotAnagrams(words[i - 1], words[i])) {
                result.push_back(words[i]);
            }
        }
      
        return result;
    }
};