class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
       
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
       
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));
        
        pq.emplace(0, 0, 0); 
        cost[0][0] = 0;
        
        while (!pq.empty()) {
            auto [currCost, x, y] = pq.top();
            pq.pop();
            
           
            if (x == rows - 1 && y == cols - 1) {
                return currCost;
            }
            
    
            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                
               
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                    int newCost = currCost + (grid[x][y] == i + 1 ? 0 : 1);
                    
               
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        pq.emplace(newCost, nx, ny);
                    }
                }
            }
        }
        
        return -1;
    }
};