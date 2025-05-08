class Solution {
   public:
	int directions[5] = {1, 0, -1, 0, 1};
	int minTimeToReach(vector<vector<int>>& moveTime) {
		int rows = moveTime.size();
		int cols = moveTime[0].size();
		vector<vector<int>> visitedTime(rows, vector<int>(cols, INT_MAX));
		visitedTime[0][0] = 0;
		vector<pair<int, int>> currentLayer{{0, 0}};
		int stepCount = 0;
		while (!currentLayer.empty()) {
			vector<pair<int, int>> nextLayer;
			++stepCount;
			for (auto [row, col] : currentLayer) {
				for (int d = 0; d < 4; ++d) {
					int newRow = row + directions[d];
					int newCol = col + directions[d + 1];
					if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
						int moveCost = (stepCount % 2 == 1) ? 1 : 2;
						int arrivalTime = max(visitedTime[row][col], moveTime[newRow][newCol]) + moveCost;
						if (visitedTime[newRow][newCol] > arrivalTime) {
							visitedTime[newRow][newCol] = arrivalTime;
							nextLayer.push_back({newRow, newCol});
						}
					}
				}
			}
			swap(currentLayer, nextLayer);
		}
		return visitedTime[rows - 1][cols - 1];
	}
};