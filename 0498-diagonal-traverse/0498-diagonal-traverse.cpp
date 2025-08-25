class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int m = mat.size(), n = mat[0].size();
        vector<int> ans(m * n);
        int row = 0, col = 0, d = 1;  // direction: 1 = up-right, -1 = down-left

        for (int i = 0; i < m * n; ++i) {
            ans[i] = mat[row][col];

            // Move in the current direction
            row -= d;
            col += d;

            // Boundary conditions
            if (row >= m) { row = m - 1; col += 2; d = -d; }
            if (col >= n) { col = n - 1; row += 2; d = -d; }
            if (row < 0)   { row = 0; d = -d; }
            if (col < 0)   { col = 0; d = -d; }
        }
        return ans;
    }
};
