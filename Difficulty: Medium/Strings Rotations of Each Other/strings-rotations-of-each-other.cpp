class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        string doubled = s1 + s1;

        if (doubled.find(s2) != string::npos) {
            return true;
        }

        return false;
    }
};