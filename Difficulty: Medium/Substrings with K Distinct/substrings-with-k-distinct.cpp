class Solution {
  public:
    int atMostK(string &s, int k) {
        unordered_map<char, int> mp;
        int i = 0, res = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (++mp[s[j]] == 1) --k;
            while (k < 0)
                if (--mp[s[i++]] == 0) ++k;
            res += j - i + 1;
        }
        return res;
    }

    int countSubstr(string &s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};