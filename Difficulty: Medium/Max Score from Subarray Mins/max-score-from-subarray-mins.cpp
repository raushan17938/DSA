class Solution {
public:
    int maxSum(vector<int> &arr) {
        int ans = 0;
        for (int i = 1; i < arr.size(); i++)
            ans = max(arr[i] + arr[i - 1], ans);
        return ans;
    }
};