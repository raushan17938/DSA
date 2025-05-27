class Solution {
  public:
    string uncommonChars(string& s1, string& s2) {
        set<char> set1(s1.begin(), s1.end());
        set<char> set2(s2.begin(), s2.end());
        set<char> result;

        // Characters in s1 but not in s2
        for (char ch : set1) {
            if (set2.find(ch) == set2.end()) {
                result.insert(ch);
            }
        }

        // Characters in s2 but not in s1
        for (char ch : set2) {
            if (set1.find(ch) == set1.end()) {
                result.insert(ch);
            }
        }

        // Convert result set to string
        return string(result.begin(), result.end());
    }
};
