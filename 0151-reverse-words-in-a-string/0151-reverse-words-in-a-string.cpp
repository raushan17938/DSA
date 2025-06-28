class Solution {
public:
    string reverseWords(string s) {
    
        trimSpaces(s);

        reverse(s.begin(), s.end());

      
        int start = 0;
        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }

private:
    void trimSpaces(string& s) {
        int n = s.size();
        int i = 0, j = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            // Copy non-space character
            if (s[i] != ' ') {
                s[j++] = s[i++];
            }
            // Copy single space, and skip multiple spaces
            else {
                s[j++] = ' ';
                while (i < n && s[i] == ' ') i++;
            }
        }

        // Remove trailing space if any
        if (j > 0 && s[j - 1] == ' ') j--;

        s.resize(j);
    }
};
