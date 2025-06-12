class Solution {
  public:
    string firstRepChar(string s) {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); ++i) {
            if (mp.find(s[i]) != mp.end()) {
          
                string res(1, s[i]);
                return res;
            }
            mp[s[i]] = i;
        }
        return "-1";
    }
};
