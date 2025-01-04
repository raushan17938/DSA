class Solution {
public:
    int countPalindromicSubsequence(string s) {
         int n = s.size();
        vector<vector<int>> left(n, vector<int>(26, 0)), right(n, vector<int>(26, 0));

        
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                for (int j = 0; j < 26; ++j) {
                    right[i][j] = right[i - 1][j];
                }
            }
            right[i][s[i] - 'a']++;
        }

        unordered_set<string> uniquePalindromes;

  
        for (int i = 1; i < n - 1; ++i) {
            char mid = s[i];
            int midIndex = mid - 'a';

          
            if (i > 1) {
                for (int j = 0; j < 26; ++j) {
                    left[i][j] = left[i - 1][j];
                }
            }
            left[i][s[i - 1] - 'a']++;

          
            for (int ch = 0; ch < 26; ++ch) {
                if (left[i][ch] > 0 && right[n - 1][ch] - right[i][ch] > 0) {
                    string palindrome = string(1, ch + 'a') + mid + string(1, ch + 'a');
                    uniquePalindromes.insert(palindrome);
                }
            }
        }

        return uniquePalindromes.size();
    }
};