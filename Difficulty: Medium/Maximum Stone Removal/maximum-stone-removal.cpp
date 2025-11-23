class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, int> row, col;
        int comp = 0;
        for (auto& s : stones) {
            if (!row.count(s[0])) row[s[0]] = comp++;
            if (!col.count(~s[1])) col[~s[1]] = comp++;
            int r = row[s[0]], c = col[~s[1]];
            if (r != c) {
                for (auto& p : row) if (p.second == c) p.second = r;
                for (auto& p : col) if (p.second == c) p.second = r;
            }
        }
        unordered_set<int> unique;
        for (auto& p : row) unique.insert(p.second);
        for (auto& p : col) unique.insert(p.second);
        return n - unique.size();
    }
};