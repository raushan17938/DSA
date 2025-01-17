class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
         int n = derived.size();
        int totalXOR = 0;

        for (int i = 0; i < n; i++) {
            totalXOR ^= derived[i];
        }

        return totalXOR == 0;
    }
};