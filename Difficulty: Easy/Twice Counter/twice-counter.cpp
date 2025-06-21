class Solution {
  public:
    int countWords(string list[], int n) {
        unordered_map<string, int> freq;

    
        for (int i = 0; i < n; ++i) {
            freq[list[i]]++;
        }

        int count = 0;
        for (const auto& pair : freq) {
            if (pair.second == 2) {
                count++;
            }
        }

        return count;
    }
};