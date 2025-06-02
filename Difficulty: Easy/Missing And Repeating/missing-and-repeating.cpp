class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n + 1, 0); // frequency array from 1 to n

        for (int num : arr) {
            freq[num]++;
        }

        int repeating = -1, missing = -1;

        for (int i = 1; i <= n; ++i) {
            if (freq[i] == 0) {
                missing = i;
            } else if (freq[i] == 2) {
                repeating = i;
            }
        }

        return {repeating, missing};
    }
};