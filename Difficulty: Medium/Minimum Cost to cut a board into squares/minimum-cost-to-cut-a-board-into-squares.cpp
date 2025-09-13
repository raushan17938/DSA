class Solution {
public:
    int minCost(int n, int m, std::vector<int>& x, std::vector<int>& y) {
        std::sort(x.begin(), x.end(), std::greater<int>());
        std::sort(y.begin(), y.end(), std::greater<int>());

        long long horizontal_pieces = 1;
        long long vertical_pieces = 1;
        long long total_cost = 0;

        int i = 0; 
        int j = 0; 

        while (i < m - 1 && j < n - 1) {

            if (x[i] >= y[j]) {
                total_cost += (long long)x[i] * horizontal_pieces;
                vertical_pieces++;
                i++;
            } else {
                total_cost += (long long)y[j] * vertical_pieces;
                horizontal_pieces++;
                j++;
            }
        }

        while (i < m - 1) {
            total_cost += (long long)x[i] * horizontal_pieces;
            vertical_pieces++;
            i++;
        }

        while (j < n - 1) {
            total_cost += (long long)y[j] * vertical_pieces;
            horizontal_pieces++;
            j++;
        }
        

        return (int)total_cost;
    }
};