class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        if (n == 0 || k == 0) return -1;

        unordered_map<char, int> charCount;
        int maxLen = -1;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            charCount[s[right]]++;

         
            while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }

            if (charCount.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};
