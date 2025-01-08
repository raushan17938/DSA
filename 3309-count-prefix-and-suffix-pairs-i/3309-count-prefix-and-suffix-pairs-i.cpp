class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        
        auto isPrefixAndSuffix = [](const string& str1, const string& str2) {
            int len1 = str1.size(), len2 = str2.size();
            if (len1 > len2) return false; 
            
            if (str2.substr(0, len1) != str1) return false;
            
            if (str2.substr(len2 - len1) != str1) return false;
            return true;
        };

       
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};