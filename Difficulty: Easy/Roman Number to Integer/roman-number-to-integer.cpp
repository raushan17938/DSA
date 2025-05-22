class Solution {
  public:
    int romanToDecimal(string &s) {
        // Map of Roman characters to integer values
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

      
        for (int i = s.length() - 1; i >= 0; i--) {
            int current = romanMap[s[i]];


            if (current < prevValue) {
                total -= current;
            } else {
                total += current;
            }

          
            prevValue = current;
        }

        return total;
    }
};
