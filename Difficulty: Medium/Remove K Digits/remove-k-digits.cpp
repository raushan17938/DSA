class Solution {
  public:
    string removeKdig(string &s, int k) {
        string ans = "";
        for (char c : s) {
            while (!ans.empty() && k > 0 && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            if (!ans.empty() || c != '0') {
                ans.push_back(c);
            }
        }
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        return ans.empty() ? "0" : ans;
    }
};