// User function template for C++

class Solution {
  public:
    int minIndexChar(string &s1, string &s2) {
        unordered_set<char> setS2(s2.begin(), s2.end());

        for (int i = 0; i < s1.length(); i++) {
            if (setS2.find(s1[i]) != setS2.end()) {
                return i;
            }
        }

        return -1;
    }
};
