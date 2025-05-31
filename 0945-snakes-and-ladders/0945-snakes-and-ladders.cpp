class Solution {
public:
    int boardSize; // The size of the board is stored at the class level.

    // The main function to play the game on the given board.
    int snakesAndLadders(vector<vector<int>>& board) {
        boardSize = board.size(); // Initial board size
        queue<int> positionsQueue; // Queue to hold positions to explore
        positionsQueue.push(1); // Starting position
        vector<bool> visited(boardSize * boardSize + 1, false); // Visited squares
        visited[1] = true; // Start square is visited
        int moves = 0; // Counter for number of moves

        // BFS to find the shortest path
        while (!positionsQueue.empty()) {
            int levelSize = positionsQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                int current = positionsQueue.front();
                positionsQueue.pop();
              
                // Check if we've reached the last square
                if (current == boardSize * boardSize) return moves;
              
                // Explore each possibility from the current position
                for (int nextPos = current + 1; nextPos <= min(current + 6, boardSize * boardSize); ++nextPos) {
                    auto position = convertTo2D(nextPos); // Convert 1D position to 2D grid indices
                    int target = nextPos;
                    int row = position.first, col = position.second;
                    // If there is a ladder or snake, move to its end.
                    if (board[row][col] != -1) target = board[row][col];
                    // If the target square is not visited, add it to queue
                    if (!visited[target]) {
                        visited[target] = true;
                        positionsQueue.push(target);
                    }
                }
            }
            ++moves; 
        }
        return -1; 
    }

   
    pair<int, int> convertTo2D(int pos) {
        int row = (pos - 1) / boardSize;
        int col = (pos - 1) % boardSize;
        if (row % 2 == 1) { 
            col = boardSize - 1 - col;
        }
         
        row = boardSize - 1 - row;
        return {row, col};
    }
};
