// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        unordered_set<char> seen;
        string result;

        for (char c : s) {
            if (seen.find(c) == seen.end()) {
                seen.insert(c);
                result += c;
            }
        }

        return result;
    }
};