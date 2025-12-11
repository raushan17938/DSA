class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> buildingsAtX;
        unordered_map<int, vector<int>> buildingsAtY;

        for (const auto& building : buildings) {
            int xCoord = building[0];
            int yCoord = building[1];
            buildingsAtX[xCoord].push_back(yCoord);
            buildingsAtY[yCoord].push_back(xCoord);
        }

        for (auto& [x, yCoords] : buildingsAtX) {
            sort(yCoords.begin(), yCoords.end());
        }
      
        for (auto& [y, xCoords] : buildingsAtY) {
            sort(xCoords.begin(), xCoords.end());
        }

        int coveredBuildingCount = 0;

        for (const auto& building : buildings) {
            int xCoord = building[0];
            int yCoord = building[1];
          
            const vector<int>& yCoordinatesAtSameX = buildingsAtX[xCoord];
            const vector<int>& xCoordinatesAtSameY = buildingsAtY[yCoord];

            
            bool hasLeftBuilding = xCoordinatesAtSameY[0] < xCoord;
            bool hasRightBuilding = xCoord < xCoordinatesAtSameY.back();
            bool hasBottomBuilding = yCoordinatesAtSameX[0] < yCoord;
            bool hasTopBuilding = yCoord < yCoordinatesAtSameX.back();
          
            if (hasLeftBuilding && hasRightBuilding && hasBottomBuilding && hasTopBuilding) {
                coveredBuildingCount++;
            }
        }

        return coveredBuildingCount;
    }
};
