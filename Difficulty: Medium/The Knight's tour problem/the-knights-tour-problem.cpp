class Solution {
public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> b(n, vector<int>(n, -1));
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        function<bool(int, int, int)> solve = [&](int x, int y, int s) {
            if (s == n * n) return true;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && b[nx][ny] == -1) {
                    b[nx][ny] = s;
                    if (solve(nx, ny, s + 1)) return true;
                    b[nx][ny] = -1;
                }
            }
            return false;
        };
        b[0][0] = 0;
        return solve(0, 0, 1) ? b : vector<vector<int>>();
    }
};