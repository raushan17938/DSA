// User function Template for C++

class Solution {
  public:
    string toLower(string& s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + ('a' - 'A'); // convert to lowercase
            }
        }
        return s;
    }
};
