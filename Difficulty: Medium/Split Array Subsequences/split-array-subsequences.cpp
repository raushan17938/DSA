class Solution {
public:
    bool isPossible(vector<int>& a, int k) {
        unordered_map<int,int> freq, need;
        for (int x : a) freq[x]++;
        for (int x : a) {
            if (!freq[x]) continue;
            freq[x]--;
            if (need[x] > 0) need[x]--, need[x + 1]++;
            else {
                for (int i = 1; i < k; i++) {
                    if (--freq[x + i] < 0) return false;
                }
                need[x + k]++;
            }
        }
        return true;
    }
};