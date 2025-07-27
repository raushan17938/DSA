class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool firstRow = false, firstCol = false;
        for (int i = 0; i < n; ++i) firstCol |= mat[i][0] == 0;
        for (int j = 0; j < m; ++j) firstRow |= mat[0][j] == 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (mat[i][j] == 0)
                    mat[i][0] = mat[0][j] = 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (!mat[i][0] || !mat[0][j])
                    mat[i][j] = 0;
        if (firstRow) fill(begin(mat[0]), end(mat[0]), 0);
        if (firstCol) for (int i = 0; i < n; ++i) mat[i][0] = 0;
    }
};