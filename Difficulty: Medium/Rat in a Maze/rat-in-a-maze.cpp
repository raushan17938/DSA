class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> res;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return res;
        string p = "";
        solve(0, 0, m, n, p, res);
        return res;
    }
    
    void solve(int i, int j, vector<vector<int>>& m, int n, string p, vector<string>& res) {
        if (i == n-1 && j == n-1) {
            res.push_back(p);
            return;
        }
        m[i][j] = 0;
        if (i+1 < n && m[i+1][j]) solve(i+1, j, m, n, p+'D', res);
        if (j-1 >= 0 && m[i][j-1]) solve(i, j-1, m, n, p+'L', res);
        if (j+1 < n && m[i][j+1]) solve(i, j+1, m, n, p+'R', res);
        if (i-1 >= 0 && m[i-1][j]) solve(i-1, j, m, n, p+'U', res);
        m[i][j] = 1;
    }
};