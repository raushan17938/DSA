class Solution {
  public:
    char firstRep(string s) {
        int freq[26] = {0};
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        for (char ch : s) {
            if (freq[ch - 'a'] > 1) {
                return ch;
            }
        }
        return '#';
    }
};
