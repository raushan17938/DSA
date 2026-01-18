class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();  
      
        vector<vector<int>> rowPrefixSum(m + 1, vector<int>(n + 1));
        vector<vector<int>> colPrefixSum(m + 1, vector<int>(n + 1));
      
      
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowPrefixSum[i][j] = rowPrefixSum[i][j - 1] + grid[i - 1][j - 1];
                colPrefixSum[i][j] = colPrefixSum[i - 1][j] + grid[i - 1][j - 1];
            }
        }
      
        for (int squareSize = min(m, n); squareSize > 1; --squareSize) {
            for (int topRow = 0; topRow + squareSize - 1 < m; ++topRow) {
                for (int leftCol = 0; leftCol + squareSize - 1 < n; ++leftCol) {
                    int bottomRow = topRow + squareSize - 1;
                    int rightCol = leftCol + squareSize - 1;
                  
                    if (isMagicSquare(grid, rowPrefixSum, colPrefixSum, 
                                     topRow, leftCol, bottomRow, rightCol)) {
                        return squareSize;
                    }
                }
            }
        }
      
        return 1;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, 
                       vector<vector<int>>& rowPrefixSum, 
                       vector<vector<int>>& colPrefixSum, 
                       int topRow, int leftCol, int bottomRow, int rightCol) {
      
        int targetSum = rowPrefixSum[topRow + 1][rightCol + 1] - rowPrefixSum[topRow + 1][leftCol];
      
        for (int row = topRow + 1; row <= bottomRow; ++row) {
            int rowSum = rowPrefixSum[row + 1][rightCol + 1] - rowPrefixSum[row + 1][leftCol];
            if (rowSum != targetSum) {
                return false;
            }
        }
      
        for (int col = leftCol; col <= rightCol; ++col) {
            int colSum = colPrefixSum[bottomRow + 1][col + 1] - colPrefixSum[topRow][col + 1];
            if (colSum != targetSum) {
                return false;
            }
        }
      
        int mainDiagonalSum = 0;
        for (int i = topRow, j = leftCol; i <= bottomRow; ++i, ++j) {
            mainDiagonalSum += grid[i][j];
        }
        if (mainDiagonalSum != targetSum) {
            return false;
        }
      
        int antiDiagonalSum = 0;
        for (int i = topRow, j = rightCol; i <= bottomRow; ++i, --j) {
            antiDiagonalSum += grid[i][j];
        }
        if (antiDiagonalSum != targetSum) {
            return false;
        }
      
        return true;
    }
};
