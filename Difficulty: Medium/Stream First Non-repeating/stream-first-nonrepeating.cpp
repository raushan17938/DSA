class Solution {
  public:
    string firstNonRepeating(string &s) {
        int count[26] = {0};
        queue<char> q;
        string ans = "";
        for (char c : s) {
            count[c - 'a']++;
            q.push(c);
            while (!q.empty() && count[q.front() - 'a'] > 1) {
                q.pop();
            }
            if (q.empty()) {
                ans += '#';
            } else {
                ans += q.front();
            }
        }
        return ans;
    }
};