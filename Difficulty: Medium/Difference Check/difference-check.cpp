class Solution {
public:
    int minDifference(vector<string>& arr) {
        vector<int> mins;
        for (auto& t : arr) {
            int h = (t[0] - '0') * 10 + (t[1] - '0');
            int m = (t[3] - '0') * 10 + (t[4] - '0');
            int s = (t[6] - '0') * 10 + (t[7] - '0');
            mins.push_back(h * 3600 + m * 60 + s);
        }
        sort(mins.begin(), mins.end());
        int res = mins[0] + 86400 - mins.back();
        for (int i = 1; i < mins.size(); i++) {
            res = min(res, mins[i] - mins[i-1]);
        }
        return res;
    }
};