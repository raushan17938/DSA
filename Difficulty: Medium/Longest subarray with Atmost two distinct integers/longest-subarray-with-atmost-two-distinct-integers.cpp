class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> mp;
        int i = 0, maxLen = 0;
        for (int j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;
            while (mp.size() > 2) {
                if (--mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};