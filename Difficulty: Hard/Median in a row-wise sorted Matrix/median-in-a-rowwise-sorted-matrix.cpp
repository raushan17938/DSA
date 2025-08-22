class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> all;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                all.push_back(mat[i][j]);
        sort(all.begin(), all.end());
        return all[(n * m) / 2];
    }
};