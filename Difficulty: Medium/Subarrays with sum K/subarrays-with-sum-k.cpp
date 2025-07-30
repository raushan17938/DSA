class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0, cnt = 0;
        mp[0] = 1;
        for (int x : arr) {
            sum += x;
            cnt += mp[sum - k];
            mp[sum]++;
        }
        return cnt;
    }
};