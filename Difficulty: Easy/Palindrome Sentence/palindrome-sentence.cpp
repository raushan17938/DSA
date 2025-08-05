class Solution {
public:
    bool isPalinSent(string s) {
        auto valid = [](char c){ return isalnum(c); };
        for (int i = 0, j = s.size()-1; i < j;) {
            if (!valid(s[i])) ++i;
            else if (!valid(s[j])) --j;
            else if (tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};