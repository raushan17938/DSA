class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.length(), j = 0;
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ) {
            if (s[i] == s[j]) lps[i++] = ++j;
            else if (j) j = lps[j - 1];
            else i++;
        }
        return lps[n - 1];
    }
};