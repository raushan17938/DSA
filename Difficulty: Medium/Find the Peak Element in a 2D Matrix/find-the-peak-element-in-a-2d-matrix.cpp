class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0, high = m - 1;
        
        while (low <= high) {
            int midCol = low + (high - low) / 2;
            
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }
            
            bool leftIsBig = (midCol > 0) && (mat[maxRow][midCol - 1] > mat[maxRow][midCol]);
            bool rightIsBig = (midCol < m - 1) && (mat[maxRow][midCol + 1] > mat[maxRow][midCol]);
            
            if (!leftIsBig && !rightIsBig) {
                return {maxRow, midCol};
            }
            
            if (rightIsBig) {
                low = midCol + 1;
            } 
            else {
                high = midCol - 1;
            }
        }
        
        return {-1, -1};
    }
};