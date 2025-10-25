class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = accumulate(arr.begin(), arr.end(), 0.0), t = s / 2;
        priority_queue<double> q(arr.begin(), arr.end());
        int ops = 0;
        while (s > t) {
            double x = q.top(); q.pop();
            s -= x / 2;
            q.push(x / 2);
            ops++;
        }
        return ops;
    }
};