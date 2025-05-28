class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        if (s.length() <= 1)
            return s;

        string result;
        result += s[0];

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != s[i - 1]) {
                result += s[i];
            }
        }

        return result;
    }
};
