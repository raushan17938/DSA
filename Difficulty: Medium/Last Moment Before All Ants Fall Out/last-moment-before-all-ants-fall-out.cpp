class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (int i = 0; i < left.size(); ++i) {
            result = result > left[i] ? result : left[i];
        }
        for (int i = 0; i < right.size(); ++i) {
            int val = n - right[i];
            result = result > val ? result : val;
        }
        return result;
    }
};