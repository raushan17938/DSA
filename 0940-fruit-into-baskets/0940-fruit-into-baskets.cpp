class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitFrequency;
        int windowStart = 0;
        int maxLength = 0;

        for (int windowEnd = 0; windowEnd < fruits.size(); ++windowEnd) {
            int rightFruit = fruits[windowEnd];
            fruitFrequency[rightFruit]++;

            while (fruitFrequency.size() > 2) {
                int leftFruit = fruits[windowStart];
                fruitFrequency[leftFruit]--;
                if (fruitFrequency[leftFruit] == 0) {
                    fruitFrequency.erase(leftFruit);
                }
                windowStart++;
            }

            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};