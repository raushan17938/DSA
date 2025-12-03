

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        map<pair<int, int>, map<long long, int>> lines;
        map<pair<int, int>, map<pair<int, int>, int>> midpoints;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long dx = points[j][0] - points[i][0];
                long long dy = points[j][1] - points[i][1];
                long long g = std::gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx; dy = -dy;
                }

                long long intercept = dx * points[i][1] - dy * points[i][0];
                lines[{ (int)dy, (int)dx }][intercept]++;

                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];
                midpoints[{mx, my}][{ (int)dy, (int)dx }]++;
            }
        }

        long long totalCalc = 0;
        for (auto const& [slope, interceptMap] : lines) {
            long long runningSum = 0;
            for (auto const& [val, count] : interceptMap) {
                totalCalc += runningSum * count;
                runningSum += count;
            }
        }

        long long parallelograms = 0;
        for (auto const& [mid, slopeMap] : midpoints) {
            long long totalSegs = 0;
            for (auto const& [slope, count] : slopeMap) totalSegs += count;
            
            long long pairs = totalSegs * (totalSegs - 1) / 2;
            long long collinear = 0;
            for (auto const& [slope, count] : slopeMap) {
                collinear += (long long)count * (count - 1) / 2;
            }
            parallelograms += (pairs - collinear);
        }

        return (int)(totalCalc - parallelograms);
    }
};