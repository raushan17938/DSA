class Solution {
public:
    vector<string> findExpr(string& s, int target) {
        vector<string> res;
        function<void(int, long, long, string)> dfs = [&](int i, long val, long prev, string path) {
            if (i == s.size()) {
                if (val == target) res.push_back(path);
                return;
            }
            for (int j = i; j < s.size(); j++) {
                if (j > i && s[i] == '0') break;
                long cur = stol(s.substr(i, j - i + 1));
                if (i == 0) dfs(j + 1, cur, cur, to_string(cur));
                else {
                    dfs(j + 1, val + cur, cur, path + "+" + to_string(cur));
                    dfs(j + 1, val - cur, -cur, path + "-" + to_string(cur));
                    dfs(j + 1, val - prev + prev * cur, prev * cur, path + "*" + to_string(cur));
                }
            }
        };
        dfs(0, 0, 0, "");
        return res;
    }
};