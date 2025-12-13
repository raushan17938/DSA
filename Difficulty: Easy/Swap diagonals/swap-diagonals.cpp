class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        int N = mat.size();
        for (int i = 0; i < N; i++) {
         
            swap(mat[i][i], mat[i][N - 1 - i]);
        }
    }
};