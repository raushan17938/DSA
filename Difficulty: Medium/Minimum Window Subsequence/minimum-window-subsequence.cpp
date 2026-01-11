class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        int minLen = 1e9, start = -1;
        int i = 0, j = 0;
        
        while (i < n) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == m) {
                    int end = i;
                    j--;
                    while (j >= 0) {
                        if (s1[i] == s2[j]) j--;
                        i--;
                    }
                    i++;
                    if (end - i + 1 < minLen) {
                        minLen = end - i + 1;
                        start = i;
                    }
                    j = 0;
                }
            }
            i++;
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};