class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int mx = 0;
                for (int di = -1; di <= 1; di++) {
                    int ni = i + di;
                    if (ni >= 0 && ni < n) mx = max(mx, mat[ni][j + 1]);
                }
                mat[i][j] += mx;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, mat[i][0]);
        return res;
    }
};