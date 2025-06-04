class Solution {
  public:

    bool kPangram(string str, int k) {
        unordered_set<char> existing;
        int totalUseful = 0;

        for (char ch : str) {
            if (isalpha(ch)) {
                ch = tolower(ch);
                if (existing.find(ch) == existing.end()) {
                    existing.insert(ch);
                }
                totalUseful++;
            }
        }

        int alreadyPresent = existing.size();
        int missing = 26 - alreadyPresent;

        // Count how many characters we *can* replace
        // Only non-useful characters are replaceable
        int replaceable = totalUseful - alreadyPresent;

        // To fix the pangram:
        // We need at least 'missing' slots to replace,
        // And k operations must be at least 'missing'
        if (missing <= k && replaceable >= missing) {
            return true;
        }

        return false;
    }
};
